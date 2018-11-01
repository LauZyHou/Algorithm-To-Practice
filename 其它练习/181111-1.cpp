#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

char c[65535];//存每次读取的段落
FILE * fp;//输入文件的文件指针
char key;//按键
bool ok = false; //指示打开文件失败

char pat[220];//要查找的串
char out[220];//要输出的串

using namespace std;

bool openFile(const char* fileName) {
    fp = fopen(fileName, "r");//打开输入文件
    if(fp == nullptr) {
        puts("打开文件失败");
        return false;
    }
    return true;
}

//在全文中搜索指定字符串
void findInAll() {
    cout << "*****************************************" << endl;
    //每次读取一段
    while(fgets(c, 65535, fp) != nullptr) {
        char *pos = strstr(c, pat); //在这段中查找第一个符合条件的位置
        if(pos == nullptr)
            continue;
        //如果找到了一个,可能有多个
        do {
            if(pos - c > 0 && pos - c < 40) { //足够小
                strncpy(out, c, 200);
            } else {
                strncpy(out, pos - 40, 200);
            }
            cout << out << "\n";
            cout << "*****************************************" << endl;
            pos = strstr(pos + 1, pat);//下一个
        } while(pos != nullptr && pos > c);
    }
}

//题库内查找
void searchInQuestion() {
    cout << "*****************************************" << endl;
    int willLine = 0; //接下来要输出的行数
    //每次读取一段
    while(fgets(c, 65535, fp) != nullptr) {
        char *pos = strstr(c, pat); //在这段中查找第一个符合条件的位置
        if(pos != nullptr) { //找到新的匹配
            willLine = 4;
            cout << c;
        } else if(willLine > 0) {
            willLine--;
            cout << c;
            if(willLine == 0) //从1行到0行
                cout << "*****************************************" << endl;
        }
    }
}

int main() {
    system("color F0");//背景亮白,文本黑色
    while(true) {
        cout << "----'a':Article search----\n";
        cout << "----'s':Search in question bank----\n";
        cout << "----any key others to quit----\n";
        cin >> key;
        if(key == 'a') {//全文搜索
            getchar();//收掉\n
            ok = openFile("input1");
            if(!ok)
                break;//打开文件失败
            while(true) {
                cout << ">>> [input pat str,'q' to quit]\n";
                gets(pat);//要查找的串
                if(pat[0] == 'q') {
                    fclose(fp);
                    break;
                }
                findInAll();//全文查找
                rewind(fp);//文件指针回退
            }
        } else if(key == 's') {//题库内查找
            getchar();//收掉\n
            ok = openFile("input2");
            if(!ok)
                break;//打开文件失败
            while(true) {
                cout << ">>> [input pat str,'q' to quit]\n";
                gets(pat);//要查找的串
                if(pat[0] == 'q') {
                    fclose(fp);
                    break;
                }
                searchInQuestion();//题库内查找
                rewind(fp);//文件指针回退
            }
        } else {
            break;
        }
    }
    system("pause");
    return 0;
}
