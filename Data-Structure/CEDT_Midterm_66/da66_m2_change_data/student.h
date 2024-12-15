#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> new_data;
    while(!a.empty()){
        std::vector<std::queue<int>> v = a.top();
        a.pop();
        for(auto &q : v){
            std::queue<int> tmp2;
            while(!q.empty()){
                int num = q.front();
                q.pop();
                if(num == from) num = to;
                tmp2.push(num);
            }
            q = tmp2;
        }
        new_data.push(v);
    }
    while(!new_data.empty()){
        a.push(new_data.top());
        new_data.pop();
    }
    
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    for(auto &x : a){
        std::priority_queue<int> tmp2;
        while(!x.second.first.empty()){
            int num = x.second.first.top();
            if(num == from) num = to;
            tmp2.push(num);
            x.second.first.pop();
        }
        x.second.first = tmp2;
        if(x.second.second == from) x.second.second = to;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> tmp_l;
    auto it = a.begin();
    while (it != a.end())
    {
        std::list<int> tmp;
        for (auto &i : it->first)
        {
            if(i == from){
                tmp.push_back(to);
            }else tmp.push_back(i);
        }
        std::map<int, std::pair<int, string>> tmp2;
        for(auto &it2 : it->second)
        {
            int key = (it2.first == from) ? to : it2.first;
            int value_first = (it2.second.first == from) ? to : it2.second.first;
            tmp2[key] = {value_first, it2.second.second};
        }
        tmp_l.insert({tmp,tmp2});
        it++;
    }
    a = tmp_l;
}

#endif
