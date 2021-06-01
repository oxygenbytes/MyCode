#pragma once
#include <set>
#include <stack>
#include <future>
#include <utility>
#include <chrono>
#include <vector>
#include <queue>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "stdlib.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
using namespace std;

struct graph_t {
	vector<pair<int, int>> edges;
	vector<int> offsets;
	vector<int> degs;
	// 2019/4/21 start
	vector<int> degsForNow;
	// 2019/4/21 end

	int n;
	int m;

	graph_t() {
		m = 0;
		n = 0;
	};
	bool adjacent(int u, int v) const
	{
		return binary_search(edges.begin() + offsets[u], edges.begin() + offsets[u] + degs[u], make_pair(u, v));
	}

	int operator()(int u, int i) const
	{
		return edges[offsets[u] + i].second;
	}

	int edge(int u, int v) const
	{
		int e = lower_bound(edges.begin() + offsets[u], edges.begin() + offsets[u] + degs[u], make_pair(u, v)) - (edges.begin() + offsets[u]);
		return e != degs[u] ? e + offsets[u] : -1;
	}
};

struct total_graph {
	graph_t Graph;
	graph_t reGraph;
	vector<bool> removed;
	vector<bool> aimSet;
	vector<int> csupp;
	vector<int> fsupp;
};

void load_total_graph(const string& fn, total_graph& totalG);

vector<int> find_trusses(int u, int v, const graph_t& uG, const graph_t& vG);

void cycle_k_truss(total_graph& totalG);

void flow_k_truss(total_graph& totalG);

void find_component(total_graph& totalG, int q);

void saveGraph(total_graph& totalG, string fn);

void removePointAndIncidentEdge(total_graph& totalG, int u);

void deleteEdge(total_graph& totalG, int u, int v, queue<int>& eHP, vector<bool>& in_eHP, int kc, int kf);

void FindDTruss(total_graph& totalG, int kc, int kf, int q);

vector<int> FindSCGAndDistance(total_graph& totalG, int q);

void FindDTrussNotComponent(total_graph& totalG, int kc, int kf);

void CopyGraph(graph_t& oldG, graph_t& newG);

void CopyTotalGraph(total_graph& total_oldG, total_graph& total_newG);

void DTrussDecomposition(string fileName, total_graph& totalG);

bool isTotalGEmpty(total_graph& totalG);

bool isDominate(pair<int, int> k1, pair<int, int> k2);

bool isTotalGEmpty(total_graph& totalG) {
	for (int i = 0; i < totalG.Graph.n; i++) {
		if (totalG.aimSet[i]) {
			return false;
		}
	}
	return true;
}

void PusheIntoHP(total_graph& totalG, int e, queue<int>& eHP, vector<bool>& in_eHP,
	int kc, int kf) {
	if (in_eHP[e] == true) return;
	if (totalG.csupp[e] < kc || totalG.fsupp[e] < kf) {
		eHP.push(e);
		in_eHP[e] = true;
	}
}

void deleteEdge(total_graph& totalG, int u, int v, queue<int>& eHP, vector<bool>& in_eHP,
	int kc, int kf) {
	totalG.removed[totalG.Graph.edge(u, v)] = true;
	totalG.csupp[totalG.Graph.edge(u, v)] = totalG.fsupp[totalG.Graph.edge(u, v)] = 0;
	totalG.Graph.degsForNow[u]--;
	totalG.reGraph.degsForNow[v]--;
	assert(totalG.reGraph.degsForNow[u] >= 0 && totalG.Graph.degsForNow[u] >= 0);
	assert(totalG.reGraph.degsForNow[v] >= 0 && totalG.Graph.degsForNow[v] >= 0);
	if (totalG.Graph.degsForNow[u] == 0 && totalG.reGraph.degsForNow[u] == 0) totalG.aimSet[u] = false;
	if (totalG.Graph.degsForNow[v] == 0 && totalG.reGraph.degsForNow[v] == 0) totalG.aimSet[v] = false;

	// cylce-support
	vector<int> ws = find_trusses(u, v, totalG.reGraph, totalG.Graph);
	for (int i = 0, w = 0; i < ws.size(); i++) {
		w = ws[i];
		int wu = totalG.Graph.edge(w, u);
		int vw = totalG.Graph.edge(v, w);
		assert(wu >= 0 && vw >= 0);
		if (totalG.removed[wu] || totalG.removed[vw]) continue;
		assert(totalG.csupp[wu] > 0 && totalG.csupp[vw] > 0);
		--totalG.csupp[wu];
		--totalG.csupp[vw];
		PusheIntoHP(totalG, wu, eHP, in_eHP, kc, kf);
		PusheIntoHP(totalG, vw, eHP, in_eHP, kc, kf);
	}

	bool vu_check = totalG.Graph.adjacent(v, u) && (!totalG.removed[totalG.Graph.edge(v, u)]);

	// u -> v <- w <- u
	ws = find_trusses(u, v, totalG.Graph, totalG.reGraph);
	vector<int> ws1_copy;
	for (int i = 0, w = 0; i < ws.size(); i++) {
		w = ws[i];
		int uw = totalG.Graph.edge(u, w);
		int wv = totalG.Graph.edge(w, v);
		assert(uw >= 0 && wv >= 0);
		if (totalG.removed[uw] || totalG.removed[wv]) continue;
		assert(totalG.fsupp[uw] > 0 && totalG.fsupp[wv] > 0);

		if (!vu_check) {
			ws1_copy.push_back(w);
			--totalG.fsupp[uw];
			--totalG.fsupp[wv];
			PusheIntoHP(totalG, uw, eHP, in_eHP, kc, kf);
			PusheIntoHP(totalG, wv, eHP, in_eHP, kc, kf);
		}
		else {
			if (!totalG.Graph.adjacent(v, w) || totalG.removed[totalG.Graph.edge(v, w)]) {
				--totalG.fsupp[uw];
				PusheIntoHP(totalG, uw, eHP, in_eHP, kc, kf);
			}
			if (!totalG.Graph.adjacent(w, u) || totalG.removed[totalG.Graph.edge(w, u)]) {
				--totalG.fsupp[wv];
				PusheIntoHP(totalG, wv, eHP, in_eHP, kc, kf);
			}
		}
	}
	sort(ws1_copy.begin(), ws1_copy.end());

	// u -> v <- w -> u
	ws = find_trusses(u, v, totalG.reGraph, totalG.reGraph);
	for (int i = 0, w = 0; i < ws.size(); i++) {
		w = ws[i];
		int wu = totalG.Graph.edge(w, u);
		int wv = totalG.Graph.edge(w, v);
		assert(wu >= 0 && wv >= 0);
		if (totalG.removed[wu] || totalG.removed[wv]) continue;
		assert(totalG.fsupp[wu] >= 0 && totalG.fsupp[wv] >= 0);

		if (!vu_check) {
			--totalG.fsupp[wu];
			PusheIntoHP(totalG, wu, eHP, in_eHP, kc, kf);
			if (!binary_search(ws1_copy.begin(), ws1_copy.end(), w)) {
				--totalG.fsupp[wv];
				PusheIntoHP(totalG, wv, eHP, in_eHP, kc, kf);
			}
		}
	}

	// u -> v -> w <- u
	ws = find_trusses(u, v, totalG.Graph, totalG.Graph);
	for (int i = 0, w = 0; i < ws.size(); i++) {
		w = ws[i];
		int uw = totalG.Graph.edge(u, w);
		int vw = totalG.Graph.edge(v, w);
		assert(uw >= 0 && vw >= 0);
		if (totalG.removed[uw] || totalG.removed[vw]) continue;
		assert(totalG.fsupp[uw] >= 0 && totalG.fsupp[vw] >= 0);

		if (!vu_check) {
			--totalG.fsupp[vw];
			PusheIntoHP(totalG, vw, eHP, in_eHP, kc, kf);
			if (!binary_search(ws1_copy.begin(), ws1_copy.end(), w)) {
				--totalG.fsupp[uw];
				PusheIntoHP(totalG, uw, eHP, in_eHP, kc, kf);
			}
		}
	}
}

void removePointAndIncidentEdge(total_graph& totalG, int u) {
	totalG.aimSet[u] = false;
	totalG.Graph.degsForNow[u] = 0;
	totalG.reGraph.degsForNow[u] = 0;
	vector<bool> cscheck(totalG.Graph.m, false);
	vector<bool> fscheck(totalG.Graph.m, false);
	for (int i = 0; i < totalG.Graph.degs[u]; i++) {
		int v = totalG.Graph(u, i);
		if (!totalG.aimSet[v]) continue;
		int e = totalG.Graph.edge(u, v);
		if (totalG.removed[e]) continue;
		totalG.removed[e] = true;
		totalG.csupp[e] = 0;
		totalG.fsupp[e] = 0;

		vector<int> ws = find_trusses(u, v, totalG.reGraph, totalG.Graph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int wu = totalG.Graph.edge(w, u);
			int vw = totalG.Graph.edge(v, w);
			assert(wu >= 0 && vw >= 0);
			if (cscheck[vw]) continue;
			if (totalG.removed[wu] || totalG.removed[vw]) continue;
			assert(totalG.csupp[wu] > 0 && totalG.csupp[vw] > 0);
			--totalG.csupp[vw];
			cscheck[vw] = true;
		}

		// u -> v <- w <- u
		ws = find_trusses(u, v, totalG.Graph, totalG.reGraph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int uw = totalG.Graph.edge(u, w);
			int wv = totalG.Graph.edge(w, v);
			assert(uw >= 0 && wv >= 0);
			if (fscheck[wv]) continue;
			if (totalG.removed[uw] || totalG.removed[wv]) continue;
			assert(totalG.fsupp[uw] > 0 && totalG.fsupp[wv] > 0);
			--totalG.fsupp[wv];
			fscheck[wv] = true;
		}

		// u -> v <- w -> u
		ws = find_trusses(u, v, totalG.reGraph, totalG.reGraph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int wu = totalG.Graph.edge(w, u);
			int wv = totalG.Graph.edge(w, v);
			assert(wu >= 0 && wv >= 0);
			if (fscheck[wv]) continue;
			if (totalG.removed[wu] || totalG.removed[wv]) continue;
			--totalG.fsupp[wv];
			fscheck[wv] = true;
		}

		// u -> v -> w <- u
		ws = find_trusses(u, v, totalG.Graph, totalG.Graph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int uw = totalG.Graph.edge(u, w);
			int vw = totalG.Graph.edge(v, w);
			assert(uw >= 0 && vw >= 0);
			if (fscheck[vw]) continue;
			if (totalG.removed[uw] || totalG.removed[vw]) continue;
			--totalG.fsupp[vw];
			fscheck[vw] = true;
		}
	}
	for (int i = 0; i < totalG.reGraph.degs[u]; i++) {
		int v = totalG.reGraph(u, i);
		if (!totalG.aimSet[v]) continue;
		int e = totalG.Graph.edge(v, u);
		if (totalG.removed[e]) continue;
		totalG.removed[e] = true;
		totalG.csupp[e] = 0;
		totalG.fsupp[e] = 0;

		//v->u->w->v
		vector<int> ws = find_trusses(v, u, totalG.reGraph, totalG.Graph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int uw = totalG.Graph.edge(u, w);
			int wv = totalG.Graph.edge(w, v);
			assert(uw >= 0 && wv >= 0);
			if (cscheck[wv]) continue;
			if (totalG.removed[uw] || totalG.removed[wv]) continue;
			assert(totalG.csupp[uw] > 0 && totalG.csupp[wv] > 0);
			--totalG.csupp[wv];
			cscheck[wv] = true;
		}

		// v -> u <- w <- v
		ws = find_trusses(v, u, totalG.Graph, totalG.reGraph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int wu = totalG.Graph.edge(w, u);
			int vw = totalG.Graph.edge(v, w);
			assert(wu >= 0 && vw >= 0);
			if (fscheck[vw]) continue;
			if (totalG.removed[wu] || totalG.removed[vw]) continue;
			assert(totalG.fsupp[wu] > 0 && totalG.fsupp[vw] > 0);
			--totalG.fsupp[vw];
			fscheck[vw] = true;
		}

		// v -> u <- w -> v
		ws = find_trusses(v, u, totalG.reGraph, totalG.reGraph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int wu = totalG.Graph.edge(w, u);
			int wv = totalG.Graph.edge(w, v);
			assert(wu >= 0 && wv >= 0);
			if (fscheck[wv]) continue;
			if (totalG.removed[wu] || totalG.removed[wv]) continue;
			--totalG.fsupp[wv];
			fscheck[wv] = true;
		}

		// v -> u -> w <- v
		ws = find_trusses(v, u, totalG.Graph, totalG.Graph);
		for (int i = 0, w = 0; i < ws.size(); i++) {
			w = ws[i];
			int uw = totalG.Graph.edge(u, w);
			int vw = totalG.Graph.edge(v, w);
			assert(uw >= 0 && vw >= 0);
			if (fscheck[vw]) continue;
			if (totalG.removed[uw] || totalG.removed[vw]) continue;
			--totalG.fsupp[vw];
			fscheck[vw] = true;
		}
	}
}

void FindDTruss(total_graph& totalG, int kc, int kf, int q) {
	FindDTrussNotComponent(totalG, kc, kf);
	find_component(totalG, q);
}

void FindDTrussNotComponent(total_graph& totalG, int kc, int kf) {
	int m = totalG.Graph.m;
	vector<pair<int, int> >& edges = totalG.Graph.edges;
	queue<int> HP;
	vector<bool> inHP(totalG.Graph.n, false);
	int degLim = max(2 * kc, kf + 1);

	for (int i = 0; i < totalG.Graph.n; i++) {
		if (!totalG.aimSet[i]) continue;
		assert((totalG.reGraph.degsForNow[i] >= 0 && totalG.Graph.degsForNow[i] > 0) ||
			(totalG.reGraph.degsForNow[i] > 0 && totalG.Graph.degsForNow[i] >= 0));
		if (totalG.reGraph.degsForNow[i] + totalG.Graph.degsForNow[i] < degLim) {
			HP.push(i);
			inHP[i] = true;
		}
	}

	while (!HP.empty()) {
		int u = HP.front();
		HP.pop();
		for (int i = 0; i < totalG.Graph.degs[u]; i++) {
			int v = totalG.Graph(u, i);
			if (!totalG.aimSet[v]) {
				assert(totalG.removed[totalG.Graph.edge(u, v)]);
				continue;
			}
			if (totalG.removed[totalG.Graph.edge(u, v)]) continue;
			if (inHP[v]) continue;
			totalG.reGraph.degsForNow[v]--;
			assert(totalG.reGraph.degsForNow[v] >= 0 && totalG.Graph.degsForNow[v] >= 0);
			if (totalG.reGraph.degsForNow[v] + totalG.Graph.degsForNow[v] < degLim) {
				HP.push(v);
				inHP[v] = true;
			}
		}
		for (int i = 0; i < totalG.reGraph.degs[u]; i++) {
			int v = totalG.reGraph(u, i);
			if (!totalG.aimSet[v]) {
				assert(totalG.removed[totalG.Graph.edge(v, u)]);
				continue;
			}
			if (totalG.removed[totalG.Graph.edge(v, u)]) continue;
			if (inHP[v]) continue;
			totalG.Graph.degsForNow[v]--;
			assert(totalG.reGraph.degsForNow[v] >= 0 && totalG.Graph.degsForNow[v] >= 0);
			if (totalG.reGraph.degsForNow[v] + totalG.Graph.degsForNow[v] < degLim) {
				HP.push(v);
				inHP[v] = true;
			}
		}
		removePointAndIncidentEdge(totalG, u);
	}

	queue<int> eHP;
	vector<bool> in_eHP(totalG.Graph.m, false);
	for (int i = 0; i < totalG.Graph.m; i++) {
		if (totalG.removed[i]) continue;
		if (totalG.csupp[i] < kc || totalG.fsupp[i] < kf) {
			eHP.push(i);
			in_eHP[i] = true;
		}
	}
	while (!eHP.empty()) {
		int e = eHP.front();
		assert(!totalG.removed[e]);
		eHP.pop();
		int u = totalG.Graph.edges[e].first;
		int v = totalG.Graph.edges[e].second;
		deleteEdge(totalG, u, v, eHP, in_eHP, kc, kf);
		assert(totalG.removed[e]);
	}
}

void load_graph(const string& fn, graph_t& G) {
	ifstream ifs(fn.c_str());
	int index = 0;
	int count = 0;
	for (string line; getline(ifs, line); ) {
		istringstream iss(line);
		int u = 0, v = 0;
		iss >> u >> v;
		if (u >= G.n || v >= G.n) G.n = max(u, v) + 1;
		if (u == v) continue;
		G.edges.push_back(make_pair(u, v));
	}
	sort(G.edges.begin(), G.edges.end());
	G.edges.erase(unique(G.edges.begin(), G.edges.end()), G.edges.end());
	G.m = G.edges.size();

	G.degs.resize(G.n);
	G.offsets.resize(G.n);
	for (int e = 0; e < G.m; ++e) ++G.degs[G.edges[e].first];
	for (int u = 0; u < G.n - 1; ++u) {
		G.offsets[u + 1] = G.offsets[u] + G.degs[u];
	}

	// 2019/4/21 start
	G.degsForNow.assign(G.degs.begin(), G.degs.end());
	// 2019/4/21 end
}

void reverse_graph(const graph_t& G, graph_t& revG, vector<bool>& aimSet) {
	aimSet.resize(G.n, false);

	revG.n = G.n;
	revG.m = G.m;
	for (int i = 0; i < G.edges.size(); i++) {
		aimSet[G.edges[i].first] = true;
		aimSet[G.edges[i].second] = true;
		pair<int, int> a = make_pair(G.edges[i].second, G.edges[i].first);
		revG.edges.push_back(a);
	}
	sort(revG.edges.begin(), revG.edges.end());

	revG.degs.resize(revG.n);
	revG.offsets.resize(revG.n);
	for (int e = 0; e < revG.m; ++e) ++revG.degs[revG.edges[e].first];
	for (int u = 0; u < revG.n - 1; ++u) revG.offsets[u + 1] = revG.offsets[u] + revG.degs[u];

	// 2019/4/21 start
	revG.degsForNow.assign(revG.degs.begin(), revG.degs.end());
	// 2019/4/21 end
}

void getsup(vector<int> &csupp0, vector<int> &asupp0, string fn) {
	ifstream ifs1((fn + "_csupport.txt").c_str());
	int index = 0;
	for (string line; getline(ifs1, line); ) {
		istringstream iss(line);
		int sup;
		iss >> sup;
		csupp0[index] = sup;
		index++;
	}

	ifstream ifs2((fn + "_fsupport.txt").c_str());
	index = 0;
	for (string line; getline(ifs2, line); ) {
		istringstream iss(line);
		int sup;
		iss >> sup;
		asupp0[index] = sup;
		index++;
	}
}

void cycle_k_truss(total_graph& totalG, const string& fn) {
	int m = totalG.Graph.m;
	vector<pair<int, int> >& edges = totalG.Graph.edges;
	totalG.csupp.clear();
	totalG.csupp.resize(m);
	//int index = 0;

	FILE *fp1;
	string fnNew1 = fn + "_csupport.txt";
	fp1 = fopen(fnNew1.c_str(), "w");

	for (int e = 0; e < m; ++e) {
		/*index++;
		cout << "counting for csupport" << index << endl;*/
		int u = edges[e].first, v = edges[e].second;
		// u -> v -> w -> u
		vector<int> ws = find_trusses(u, v, totalG.reGraph, totalG.Graph);
		totalG.csupp[e] = ws.size();

		fprintf(fp1, "%d ", ws.size());
		fprintf(fp1, "\n");
	}

	fclose(fp1);
}

void flow_k_truss(total_graph& totalG, const string& fn) {
	int m = totalG.Graph.m;
	vector<pair<int, int> >& edges = totalG.Graph.edges;
	totalG.fsupp.clear();
	totalG.fsupp.resize(m);
	//int index = 0;

	FILE *fp;
	string fnNew = fn + "_fsupport.txt";
	fp = fopen(fnNew.c_str(), "w");

	for (int e = 0; e < m; ++e) {
		/*index++;
		cout << "counting for fsupport" << index << endl;*/
		int u = edges[e].first, v = edges[e].second;
		vector<int> ws1;
		vector<int> ws2;
		vector<int> ws3;
		ws1 = find_trusses(u, v, totalG.Graph, totalG.reGraph); // u -> v <- w <- u
		ws2 = find_trusses(u, v, totalG.reGraph, totalG.reGraph); // u -> v <- w -> u
		ws3 = find_trusses(u, v, totalG.Graph, totalG.Graph); // u -> v -> w <- u
		sort(ws1.begin(), ws1.end());
		sort(ws2.begin(), ws2.end());
		sort(ws3.begin(), ws3.end());

		vector<int> ivec(ws1.size() + ws2.size());
		auto iter = set_union(ws1.begin(), ws1.end(), ws2.begin(), ws2.end(), ivec.begin());
		ivec.resize(iter - ivec.begin());
		vector<int> ivec2(ivec.size() + ws3.size());
		auto iter2 = set_union(ivec.begin(), ivec.end(), ws3.begin(), ws3.end(), ivec2.begin());

		int union_size = iter2 - ivec2.begin();
		totalG.fsupp[e] = union_size;

		fprintf(fp, "%d ", union_size);
		fprintf(fp, "\n");
	}

	fclose(fp);
}

void load_total_graph(const string& fn, total_graph& totalG) {
	load_graph(fn, totalG.Graph);
	reverse_graph(totalG.Graph, totalG.reGraph, totalG.aimSet);
	totalG.removed.resize(totalG.Graph.m, false);
	totalG.csupp.resize(totalG.Graph.m, 0);
	totalG.fsupp.resize(totalG.Graph.m, 0);

	ifstream ifs1((fn + "_csupport.txt").c_str());
	ifstream ifs2((fn + "_fsupport.txt").c_str());
	if (ifs1&&ifs2) {
		cout << "support file already exists, loading..." << endl;
		getsup(totalG.csupp, totalG.fsupp, fn);
		cout << "loading complete!" << endl;
	}
	else {
		cout << "support file not exists, creating..." << endl;
		flow_k_truss(totalG, fn);
		cycle_k_truss(totalG, fn);
		cout << "creating complete" << endl;
	}
}

vector<int> find_trusses(int u, int v, const graph_t& uG, const graph_t& vG) {
	vector<int> ws;
	if (uG.degs[u] < vG.degs[v]) {
		for (int i = 0; i < uG.degs[u]; ++i) {
			int w = uG(u, i);
			if (w == u || w == v)
				continue;
			if (vG.adjacent(v, w))
				ws.push_back(w);
		}
	}
	else {
		for (int i = 0; i < vG.degs[v]; ++i) {
			int w = vG(v, i);
			if (w == u || w == v)
				continue;
			if (uG.adjacent(u, w))
				ws.push_back(w);
		}
	}
	return ws;
}

void cycle_k_truss(total_graph& totalG) {
	int m = totalG.Graph.m;
	vector<pair<int, int> >& edges = totalG.Graph.edges;
	totalG.csupp.clear();
	totalG.csupp.resize(m);
	//int index = 0;

	for (int e = 0; e < m; ++e) {
		if (totalG.removed[e]) {
			totalG.csupp[e] = 0;
			continue;
		}
		int u = edges[e].first, v = edges[e].second;
		// u -> v -> w -> u
		//vector<int> ws = find_trusses(u, v, totalG.reGraph, totalG.Graph);
		vector<int> ws;
		for (int i = 0; i < totalG.Graph.degs[v]; ++i) {
			int w = totalG.Graph(v, i);
			if (w == u || w == v)
				continue;
			if (!totalG.aimSet[w]) continue;
			if (totalG.removed[totalG.Graph.edge(v, w)]) continue;
			if (!totalG.Graph.adjacent(w, u)) continue;
			if (totalG.removed[totalG.Graph.edge(w, u)]) continue;
			ws.push_back(w);
		}
		totalG.csupp[e] = ws.size();
	}
}

void flow_k_truss(total_graph& totalG) {
	int m = totalG.Graph.m;
	vector<pair<int, int> >& edges = totalG.Graph.edges;
	totalG.fsupp.clear();
	totalG.fsupp.resize(m);
	//int index = 0;

	for (int e = 0; e < m; ++e) {
		if (totalG.removed[e]) {
			totalG.fsupp[e] = 0;
			continue;
		}
		int u = edges[e].first, v = edges[e].second;
		vector<int> ws1;
		vector<int> ws2;
		vector<int> ws3;
		//ws1 = find_trusses(u, v, totalG.Graph, totalG.reGraph); // u -> v <- w <- u
		//ws2 = find_trusses(u, v, totalG.reGraph, totalG.reGraph); // u -> v <- w -> u
		//ws3 = find_trusses(u, v, totalG.Graph, totalG.Graph); // u -> v -> w <- u
		for (int i = 0; i < totalG.Graph.degs[u]; ++i) {
			int w = totalG.Graph(u, i);
			if (w == u || w == v)
				continue;
			if (!totalG.aimSet[w]) continue;
			if (totalG.removed[totalG.Graph.edge(u, w)]) continue;
			if (!totalG.Graph.adjacent(w, v)) continue;
			if (totalG.removed[totalG.Graph.edge(w, v)]) continue;
			ws1.push_back(w);
		}
		for (int i = 0; i < totalG.reGraph.degs[u]; ++i) {
			int w = totalG.reGraph(u, i);
			if (w == u || w == v)
				continue;
			if (!totalG.aimSet[w]) continue;
			if (totalG.removed[totalG.Graph.edge(w, u)]) continue;
			if (!totalG.Graph.adjacent(w, v)) continue;
			if (totalG.removed[totalG.Graph.edge(w, v)]) continue;
			ws2.push_back(w);
		}
		for (int i = 0; i < totalG.Graph.degs[u]; ++i) {
			int w = totalG.Graph(u, i);
			if (w == u || w == v)
				continue;
			if (!totalG.aimSet[w]) continue;
			if (totalG.removed[totalG.Graph.edge(u, w)]) continue;
			if (!totalG.Graph.adjacent(v, w)) continue;
			if (totalG.removed[totalG.Graph.edge(v, w)]) continue;
			ws3.push_back(w);
		}

		sort(ws1.begin(), ws1.end());
		sort(ws2.begin(), ws2.end());
		sort(ws3.begin(), ws3.end());

		vector<int> ivec(ws1.size() + ws2.size());
		auto iter = set_union(ws1.begin(), ws1.end(), ws2.begin(), ws2.end(), ivec.begin());
		ivec.resize(iter - ivec.begin());
		vector<int> ivec2(ivec.size() + ws3.size());
		auto iter2 = set_union(ivec.begin(), ivec.end(), ws3.begin(), ws3.end(), ivec2.begin());

		int union_size = iter2 - ivec2.begin();
		totalG.fsupp[e] = union_size;
	}
}

void CopyGraph(graph_t& oldG, graph_t& newG) {
	newG.m = oldG.m;
	newG.n = oldG.n;
	newG.degs.assign(oldG.degs.begin(), oldG.degs.end());
	newG.edges.assign(oldG.edges.begin(), oldG.edges.end());
	newG.offsets.assign(oldG.offsets.begin(), oldG.offsets.end());
	newG.degsForNow.assign(oldG.degsForNow.begin(), oldG.degsForNow.end());
}

void CopyTotalGraph(total_graph& total_oldG, total_graph& total_newG) {
	total_newG.aimSet.assign(total_oldG.aimSet.begin(), total_oldG.aimSet.end());
	total_newG.csupp.assign(total_oldG.csupp.begin(), total_oldG.csupp.end());
	total_newG.fsupp.assign(total_oldG.fsupp.begin(), total_oldG.fsupp.end());
	total_newG.removed.assign(total_oldG.removed.begin(), total_oldG.removed.end());
	CopyGraph(total_oldG.Graph, total_newG.Graph);
	CopyGraph(total_oldG.reGraph, total_newG.reGraph);
}

void find_component(total_graph& totalG, int q) {
	vector<bool> stackCheck(totalG.Graph.n, false);
	stack<int> S;
	S.push(q);
	stackCheck[q] = true;

	int round = 0;
	while (!S.empty()) {
		int vq = S.top();
		S.pop();
		round++;

		//vq->u
		for (int i = 0; i < totalG.Graph.degs[vq]; ++i) {
			int u = totalG.Graph(vq, i);
			if (stackCheck[u]) {
				continue;
			}
			if (totalG.removed[totalG.Graph.edge(vq, u)]) continue;
			if (!totalG.aimSet[u]) continue;
			S.push(u);
			stackCheck[u] = true;
		}

		//u->vq
		for (int i = 0; i < totalG.reGraph.degs[vq]; ++i) {
			int u = totalG.reGraph(vq, i);
			if (stackCheck[u]) {
				continue;
			}
			if (totalG.removed[totalG.Graph.edge(u, vq)]) continue;
			if (!totalG.aimSet[u]) continue;
			S.push(u);
			stackCheck[u] = true;
		}
	}

	if (round <= 1)
		stackCheck[q] = false;

	totalG.aimSet.assign(stackCheck.begin(), stackCheck.end());

	for (int i = 0; i < totalG.Graph.m; i++) {
		if (totalG.removed[i]) continue;
		int u = totalG.Graph.edges[i].first;
		int v = totalG.Graph.edges[i].second;
		if (totalG.aimSet[u] && totalG.aimSet[v]) continue;
		totalG.removed[i] = true;
	}
}

vector<int> FindSCGAndDistance(total_graph& totalG, int q) {
	vector<int> distance(totalG.Graph.n, -1);

	queue<int> Q;
	vector<bool> inQ1(totalG.Graph.n, false);
	vector<int> dis1(totalG.Graph.n, -1);
	vector<bool> aimSet1(totalG.Graph.n, false);
	Q.push(q);
	dis1[q] = 0;
	inQ1[q] = true;

	int round1 = 0;
	while (!Q.empty()) {
		round1++;
		int v = Q.front();
		Q.pop();
		aimSet1[v] = true;
		for (int i = 0; i < totalG.Graph.degs[v]; ++i) {
			int w = totalG.Graph(v, i);
			if (!totalG.aimSet[w]) {
				assert(totalG.removed[totalG.Graph.edge(v, w)]);
				continue;
			}
			if (totalG.removed[totalG.Graph.edge(v, w)]) continue;
			if (!inQ1[w]) {
				assert(dis1[w] == -1);
				dis1[w] = dis1[v] + 1;
				Q.push(w);
				inQ1[w] = true;
			}
		}
	}

	if (round1 <= 1) {
		aimSet1[q] = false;
	}

	vector<bool> aimSet2(totalG.Graph.n, false);
	vector<bool> inQ2(totalG.Graph.n, false);
	vector<int> dis2(totalG.Graph.n, -1);
	Q.push(q);
	dis2[q] = 0;
	inQ2[q] = true;

	int round2 = 0;
	while (!Q.empty()) {
		round2++;
		int v = Q.front();
		Q.pop();
		aimSet2[v] = true;
		for (int i = 0; i < totalG.reGraph.degs[v]; ++i) {
			int w = totalG.reGraph(v, i);
			if (!totalG.aimSet[w]) {
				assert(totalG.removed[totalG.Graph.edge(w, v)]);
				continue;
			}
			if (totalG.removed[totalG.Graph.edge(w, v)]) continue;
			if (!inQ2[w]) {
				assert(dis2[w] == -1);
				dis2[w] = dis2[v] + 1;
				Q.push(w);
				inQ2[w] = true;
			}
		}
	}

	if (round2 <= 1) {
		aimSet2[q] = false;
	}

	for (int i = 0; i < totalG.Graph.n; i++) {
		if (aimSet1[i] && aimSet2[i]) {
			totalG.aimSet[i] = true;
			distance[i] = max(dis1[i], dis2[i]);
		}
		else {
			totalG.aimSet[i] = false;
		}
	}

	for (int i = 0; i < totalG.Graph.m; i++) {
		if (totalG.removed[i]) continue;
		int u = totalG.Graph.edges[i].first;
		int v = totalG.Graph.edges[i].second;
		if (totalG.aimSet[u] && totalG.aimSet[v]) continue;
		totalG.removed[i] = true;
	}

	return distance;
}

void saveGraph(total_graph& totalG, string fn) {
	FILE* fp_query = fopen(fn.c_str(), "w");
	for (int e = 0; e < totalG.Graph.m; ++e) {
		if (totalG.removed[e]) continue;
		int x = totalG.Graph.edges[e].first;
		int y = totalG.Graph.edges[e].second;
		fprintf(fp_query, "%d %d\n", x, y);
	}
	fclose(fp_query);
	cout << fn + " complete!" << endl;
}

bool isDominate(pair<int, int> k1, pair<int, int> k2) {
	if ((k1.first > k2.first&& k1.second >= k2.second) || (k1.first >= k2.first&& k1.second > k2.second)) return true;
	else return false;
}

void SkyTruss(int e, pair<int, int> k, vector<vector<pair<int, int> > >& ST) {
	int Flag = false;
	for (int i = 0; i < ST[e].size(); i++) {
		if (isDominate(ST[e][i], k)) Flag = true;
		else if (isDominate(k, ST[e][i])) {
			vector <pair<int, int> >::iterator k = ST[e].begin();
			k = k + i;
			ST[e].erase(k);
			break;
		}
	}
	if (!Flag) ST[e].push_back(k);
}

void saveSkyTruss(string fileName, vector<vector<pair<int, int> > >& ST) {
	string fn_query = fileName + "_ST.txt";
	cout << "start saving " << fn_query << endl;
	FILE* fp_query = fopen(fn_query.c_str(), "w");
	for (int e = 0; e < ST.size(); ++e) {
		for (int k = 0; k < ST[e].size(); k++) {
			int x = ST[e][k].first;
			int y = ST[e][k].second;
			fprintf(fp_query, "%d %d ", x, y);
		}
		fprintf(fp_query, "\n");
	}
	fclose(fp_query);
}

void DTrussDecomposition(string fileName, total_graph& totalG) {
	vector<vector<pair<int, int> > > ST(totalG.Graph.m);

	/*cycle_k_truss(totalG);
	flow_k_truss(totalG);*/
	int kc = 0, kf = 0;
	vector<total_graph> Di_0;
	total_graph Dc;
	CopyTotalGraph(totalG, Dc);
	total_graph D0;
	CopyTotalGraph(Dc, D0);
	Di_0.push_back(D0);
	while (!isTotalGEmpty(Dc)) {
		cout << "kc1:" << kc << endl;
		kc++;
		clock_t start = clock();
		FindDTrussNotComponent(Dc, kc, kf);
		clock_t ends = clock();
		double time = (double)(ends - start) / CLOCKS_PER_SEC;
		cout << time << endl;
		total_graph Di;
		CopyTotalGraph(Dc, Di);
		Di_0.push_back(Di);
	}

	for (int i = 0; i < kc; i++) {
		cout << "kc2:" << i << endl;
		clock_t start = clock();
		while (!isTotalGEmpty(Di_0[i])) {
			int FS = -1;
			int min_fsupp_e;
			for (int j = 0; j < Di_0[i].Graph.m; j++) {
				if (Di_0[i].removed[j]) continue;
				else if (FS == -1 || Di_0[i].fsupp[j] < FS) {
					FS = Di_0[i].fsupp[j];
					min_fsupp_e = j;
				}
			}

			assert(FS != -1);

			queue<int> eHP;
			vector<bool> in_eHP(Di_0[i].Graph.m, false);
			for (int j = 0; j < Di_0[i].Graph.m; j++) {
				if (Di_0[i].removed[j]) continue;
				if (Di_0[i].csupp[j] < i || Di_0[i].fsupp[j] <= FS) {
					eHP.push(j);
					in_eHP[j] = true;
				}
			}

			while (!eHP.empty()) {
				int e = eHP.front();
				eHP.pop();
				int u = Di_0[i].Graph.edges[e].first;
				int v = Di_0[i].Graph.edges[e].second;
				SkyTruss(e, make_pair(i, FS), ST);
				deleteEdge(Di_0[i], u, v, eHP, in_eHP, i, FS);
			}
		}
		clock_t ends = clock();
		double time = (double)(ends - start) / CLOCKS_PER_SEC;
		cout << time << endl;
	}

	saveSkyTruss(fileName, ST);
}

int main()
{
	total_graph totalG;
	cout << "input the filename:" << endl;
	string fn;
	cin >> fn;
	load_total_graph(fn, totalG);
	clock_t start = clock();
	DTrussDecomposition(fn, totalG);
	clock_t ends = clock();
	double time_global = (double)(ends - start) / CLOCKS_PER_SEC;
	cout << time_global << endl;
	return 0;
}