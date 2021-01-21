///////////////
//НЕ РАБОТАЕТ//
///////////////
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
//#include "stdc++.h"
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;

map< int, map<int, int> > automaton;
string word;
vector<int> term;
int alph, atm, n, t;

vector< vector<int> > equivalence(2, std::vector<int>(1));

int now; // now=0..1; next = 1-now

int k;
int free_eq; // следующий незанятый номер класса

void findEquivalenceClasses(){
  equivalence[0].resize(t);
  equivalence[1].resize(atm - t);

  int pos1=0, pos2=0;

  for (int i = 0; i < atm; ++i)
  {
    if (find(term.begin(), term.end(), i) != term.end()){
      equivalence[0][pos1] = i;
      pos1++;
    } else {
      equivalence[1][pos2] = i;
      pos2++;
    }
  }

  vector< vector <vector<int> > > s;

  for (int i = 0; i < alph; ++i)
  {
    s.push_back(vector< vector<int> > {equivalence[0], {i}});
    s.push_back(vector< vector<int> > {equivalence[1], {i}});
  }

  while (s.size() > 0){
    vector< vector<int> > para{s[s.size() - 1][0], s[s.size() - 1][1]};
    s.pop_back();
    if (find(equivalence.begin(), equivalence.end(), para[0]) == equivalence.end()){
      continue;
    }
    vector< vector<int> > dest(atm, vector<int>(0));
    for (int i = 0; i < para[0].size(); ++i)
    {
      dest[automaton[para[0][i]][para[1][0]]].push_back(para[0][i]);
    }

    vector<int> r1(0);
    vector<int> r2(0);

    int pos = 0;

    while (r1.size() == 0){
      r1 = dest[pos];
      pos++;
    }

    if (r1.size() < para[0].size()){
      for (pos; pos < atm; pos++){
        r2.insert(r2.end(), dest[pos].begin(), dest[pos].end());
      }

      bool selfcheck = true;

      for (int i = 0; i < para[0].size(); ++i)
      {
        if (find(para[0].begin(), para[0].end(), automaton[para[0][i]][para[1][0]]) == para[0].end()){
          selfcheck = false;
        }
      }
      if (selfcheck){
        continue;
      }

      for (int i = 0; i < alph; ++i)
      {
        s.push_back(vector< vector<int> > {r1, {i}});
        s.push_back(vector< vector<int> > {r2, {i}});
      }
      if (find(equivalence.begin(), equivalence.end(), para[0]) != equivalence.end()){
        equivalence.erase(remove(equivalence.begin(), equivalence.end(), para[0]), equivalence.end());
        equivalence.push_back(r1);
        equivalence.push_back(r2);

        /*//temp
        cout <<  "para ";
        for (int i = 0; i < para[0].size(); ++i)
        {
          cout << para[0][i] << " ";
        }
        cout << "\nr1: ";
        for (int i = 0; i < r1.size(); ++i)
        {
          cout << r1[i] << " ";
        }
        cout << "r2: ";
        for (int i = 0; i < r2.size(); ++i)
        {
          cout << r2[i] << " ";
        }
        cout << "\n\n";
        //temp
        */
      }
    }
  }


}

void  remove_unachievable_rules(){
       T_states_names  res_states_names;

       //Вставляем в res_states_names имя стартового состояния.
       res_states_names.insert(rules_with_first_start_state_.begin()->first.first);

       //В цикле пробегаемся по всем правилам, и, если у какого-то правила
       //начальное состояние есть в res_states_names, а конечное отстутствует,
       //то поместить его туда и повторить цикл.
       bool  repeate = false;
       do
       {
           repeate = false;
           for(T_rules::const_iterator  rule_it = rules_.begin();
               rule_it != rules_.end(); ++rule_it)
           {
               T_state_name  begin_name  = rule_it->first.first;
               T_state_name  end_name    = rule_it->second;

               if(     res_states_names.count(begin_name)
                   && !res_states_names.count(end_name)   )
               {
                   res_states_names.insert(end_name);
                   repeate = true;
               }
           }
       }while(repeate);

       //Утверждение: имена всех достижимых состояний содержатся в res_states_names.
       //Удаляем из rules_ все правила, имен начальных состояний которых нет
       //в res_states_names.
       for(T_rules::iterator  rule_it = rules_.begin();
           rule_it != rules_.end(); )
       {
           if( !res_states_names.count(rule_it->first.first) )
           {
               T_rules::const_iterator  rule_it_for_erase = rule_it;
               ++rule_it;
               rules_.erase(rule_it_for_erase);
           }
           else
           {
               ++rule_it;
           }
       }
   }

int main(){
    cin >> atm >> t >> alph;
  term.resize(t);

  for (int i = 0; i < t; ++i){
    cin >> term[i];
  }

  n = atm * alph;

    for (int i = 0; i < n; ++i){
        char letter;
        std::vector<int> line(2);
        cin >> line[0] >> letter >> line[1];
        automaton[line[0]][static_cast<int>(letter - 'a')] = line[1];
    }
  if (t==atm){
    cout << 1 << "\n";
    exit(0);
  }
  findEquivalenceClasses();
  remove_unachievable_rules();
  cout << equivalence.size() << "\n";
  /*for (int i = 0; i < equivalence.size(); ++i)
  {
    for (int j = 0; j < equivalence[i].size(); ++j)
    {
      cout << equivalence[i][j] << " ";
    }
    cout << "\n";
  }*/

return 0;
}
