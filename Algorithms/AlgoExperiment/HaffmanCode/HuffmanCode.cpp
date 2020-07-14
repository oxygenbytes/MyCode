#include <bits/stdc++.h>
using namespace std;

const int UniqueSymbols = 1 << CHAR_BIT; // 256 unicode
vector<char> SampleString;
typedef vector<bool> HuffmanCode;
typedef map<char,HuffmanCode> HuffmanCodeMap;
typedef map<string,char> huffmanCodeMap;
const string pwd = "/home/fantasy/Code/Cplusplus/HaffmanCode/";

class HuffmanTreeNode
{
public:
    const int f;
    bool tag;
    virtual ~HuffmanTreeNode() {} // 析构函数
protected:
    HuffmanTreeNode(int f,bool tag) : f(f) ,tag(tag) {} // f是频率
};

class InternalNode : public HuffmanTreeNode // 内节点
{
public:
    HuffmanTreeNode *const left;
    HuffmanTreeNode *const right;
    InternalNode(HuffmanTreeNode* c0,HuffmanTreeNode* c1) : 
        HuffmanTreeNode(c0->f + c1->f,true),left(c0),right(c1) {}
    ~InternalNode()
    {
        delete left;
        delete right;
    }
};

class LeafNode : public HuffmanTreeNode
{
public:
    const char c;
    LeafNode(int f,char c) : HuffmanTreeNode(f,false),c(c) {} 
    // 子类构造函数初始化，先执行父类初始化函数
};

struct NodeCmp
{
    bool operator()(const HuffmanTreeNode* lhs ,const HuffmanTreeNode* rhs) const {return lhs->f > rhs->f;}
    // 函数末尾加const 常成员函数  第一个保证显式调用不被修改， 第二个保证隐式调用不被修改。
};

HuffmanTreeNode* BuildTree(const int (&frequencies)[UniqueSymbols])
{
    priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,NodeCmp> trees;
    // trees是小顶堆
    for(int i =0;i < UniqueSymbols;++i)
    {
        if(frequencies[i] != 0)
            trees.push(new LeafNode(frequencies[i],(char)i));
    }
    // 利用小顶堆构建哈弗曼树
    while(trees.size() > 1)
    {
        //左0，右1
        HuffmanTreeNode* childL = trees.top();
        trees.pop();

        HuffmanTreeNode* childR = trees.top();
        trees.pop();

        HuffmanTreeNode* parent = new InternalNode(childL,childR);
        trees.push(parent);
    }
    return trees.top();
}
// prefix 是 vector
void GenerateCodes(const HuffmanTreeNode* headNode,const HuffmanCode& prefix,HuffmanCodeMap& outCodes)
{
    // headNode HuffmanTreeNode -> LeafNode 动态转型
    if(const LeafNode* lf = dynamic_cast<const LeafNode*>(headNode)) //叶子节点
    {
        outCodes[lf->c] = prefix;
    }
    else if (const InternalNode* in = dynamic_cast<const InternalNode*>(headNode)) // 内节点
    {
        HuffmanCode leftPrefix = prefix;
        leftPrefix.push_back(false);
        GenerateCodes(in->left,leftPrefix,outCodes);

        HuffmanCode rightPrefix = prefix;
        rightPrefix.push_back(true);
        GenerateCodes(in->right,rightPrefix,outCodes);
    }
}

void ReadSample(string DocumentName){
    DocumentName = pwd + DocumentName;
    fstream readString;
    readString.open(DocumentName,ios::in);
    if(!readString){
        cout<<"fail to read string!";
    }
    readString>>noskipws; // 不跳过空格
    char c;
    while(!readString.eof()){
        readString>>c;
        SampleString.push_back(c);
    }
}
void WriteHuffmanCode(string DocumentName,const HuffmanCodeMap codes){
    DocumentName = pwd + DocumentName;
    fstream write;
    write.open(DocumentName,ios::out);
    if(!write){
        cout<<"fail to write string!";
    }
    write<<noskipws;
    for(HuffmanCodeMap::const_iterator it = codes.begin();it != codes.end();++it)
    {
        write<<it->first<<" ";
        copy(it->second.begin(),it->second.end(),ostream_iterator<bool>(write));
        write<<endl;
    }
    
}

void WriteSampleCode(string DocumentName,const HuffmanCodeMap codes){
    DocumentName = pwd + DocumentName;
    fstream write;
    write.open(DocumentName,ios::out);
    for(int i = 0;i < SampleString.size();i++){
        HuffmanCodeMap::const_iterator it = codes.find(SampleString[i]);
        if( it != codes.end()){
            copy(it->second.begin(),it->second.end(),ostream_iterator<bool>(write));
        }
    }
}
// c++ 文件操作都是以内存为标准，
void decode(string DocumentName,const HuffmanTreeNode* headNode,vector<char> bits,huffmanCodeMap outCodes){
    fstream file;
    DocumentName = pwd + DocumentName;
    file.open(DocumentName,ios::out);
    for(int i = 0;i < bits.size();i++){
        InternalNode *ptr =(InternalNode*)headNode;
        string temp = "";
        while(ptr->tag){
            if(bits[i] == '0'){
                ptr = (InternalNode*)(ptr -> left);
                temp += '0';
                i++;
            }else
            {
                ptr = (InternalNode*)(ptr -> right);
                temp += '1';
                i++;
            }
        }
        i--;
        char s = outCodes[temp];
        file<<s;
    }

}
// 读取保存的哈夫曼编码内容
void readMap(huffmanCodeMap& codes,string DocumentName){
    DocumentName = pwd + DocumentName;
    fstream write;
    write.open(DocumentName,ios::in);
    char s;
    char temp;
    write>>noskipws;
    string code;
    while(!write.eof()){
        write>>s;
        write>>temp;
        write>>code;
        write>>temp;
        codes[code]= s;
    }
}
// 读取文件的哈夫曼编码
void readMakeUp(string DocumentName,vector<char>& makeup){
    DocumentName = pwd + DocumentName;
    fstream read;
    read.open(DocumentName,ios::in);
    char s;
    while(!read.eof()){
        read>>s;
        makeup.push_back(s);
    }
}

void  SaveFrequency(string DocumentName,const int (&frequencies)[UniqueSymbols]){
    fstream file;
    DocumentName = pwd + DocumentName;
    file.open(DocumentName,ios::out);
    char s;
    for(int i = 0;i < UniqueSymbols;i++){
        if(frequencies[i] != 0){
            s = i;
            file<<s<<" ";
            file<<frequencies[i]<<endl;
        }
    }
}
int main()
{
    const string sample_file = "Sample.txt";
    const string frequency_file = "Frequency.txt";
    const string makeup_file = "MakeUp.txt";
    const string result_file = "Result.txt";
    const string huffmancode_file = "HuffmanCode.txt";

    // 1. build frequency table
    ReadSample(sample_file);
    int frequencies[UniqueSymbols] = {0};
    for(int i = 0;i < SampleString.size();i++){
        ++frequencies[SampleString[i]];
    }
    SaveFrequency(frequency_file,frequencies);

    // 2. bulid huffman tree
    HuffmanTreeNode* root = BuildTree(frequencies);
    HuffmanCodeMap codes; // 哈夫曼编码表
    GenerateCodes(root,HuffmanCode(),codes);
    // delete root;
    WriteHuffmanCode(huffmancode_file,codes);
    WriteSampleCode(makeup_file,codes);
    huffmanCodeMap Codes; // 哈夫曼解码表

    // 3.decode huffman code
    readMap(Codes,huffmancode_file);
    vector<char> makeup;
    readMakeUp("MakeUp.txt",makeup);
    decode(result_file,root,makeup,Codes);
    return 0;
}
