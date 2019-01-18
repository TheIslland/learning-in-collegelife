/*************************************************************************
	> File Name: 异常处理.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 14时48分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
int main() {
    try{
        throw 1;
    } catch(char c) {
        cout << "catch(char c) = "<< c << endl;
    } catch(short s) {
        cout << "catch(short s) = " << s << endl;
    } catch (double d) {
        cout << "catch(double d) = " << d << endl;
    } catch(int i) {
        cout << "catch(int i)" << i << endl;
    } catch(...) {
        cout << "catch(...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}
