#include<string>
#include<iostream>
void replaceSpace(char *str,int length) {
    int space = 0;
    int real_length =0;
    for(int i = 0;str[i] != '\0'; i++ ){
        if(str[i] == ' ')
            space ++;
        real_length ++;
    }
    std::cout<<"space :"<<space<<std::endl;
    int p1 = real_length-1;
    int after_lenght = real_length + space * 2;
    int p2 = after_lenght-1;
    std::cout<<"p1"<<p1<<std::endl<<"p2"<<p2<<std::endl;
    char temp[3] = {'0','2', '%'};
    while(p1 >= 0 && p2 > p1){
        if(str[p1] != ' '){
            str[p2] = str[p1];
            p2 --;
        }
            
        else 
            for(int i=0;i<3;i++){
                str[p2] = temp[i];
                p2 --;
            }
        p1 --;

        std::cout<<p1<<":"<<p2<<std::endl;
    }
    
}

int main(){
    char str[] = " helloworld";
    replaceSpace(str,13);
    std::cout<<"str"<<str;
    return 0;
}