#include <string>
using namespace std;

class Solution {
private:
    void moveBack(string& s, int index){
        s.resize(s.length()+2);
        for(int i=s.length(); i>index+2; i--){
            s[i] = s[i-2];
        }
        s[index] = '%';
        s[index+1] = '2';
        s[index+2] = '0';
    }
public:
    string replaceSpace(string s) {
        if(s.empty()) return s;
        int index=0;
        while(s[index] != '\0'){
            if(s[index] == ' '){
                moveBack(s, index);
            }
            index++;
        }

        return s;
    }
};

int main(){
    Solution solution;
    solution.replaceSpace("We Are Happy");
}