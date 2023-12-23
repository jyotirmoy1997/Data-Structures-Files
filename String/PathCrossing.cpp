#include<bits/stdc++.h>
using namespace std;
bool isPathCrossing(string path){
    int xCord = 0, yCord = 0;
    set<pair<int, int>> st;
    st.insert({0, 0});
    for(auto it : path){
        if(it == 'N')
            yCord++;
        
        else if(it == 'S')
            yCord--;
        
        else if(it == 'W')
            xCord--;

        else if(it == 'E')
            xCord++;

        if(st.find({xCord, yCord}) != st.end())
            return true;

        st.insert({xCord, yCord});
    }
    return false;
}
int main(){

}