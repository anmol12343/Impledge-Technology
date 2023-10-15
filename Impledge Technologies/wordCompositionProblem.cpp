#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
bool isCompounded(string &s,unordered_map<string,bool> &mp,int i = 0){
   if(i>=s.size()){
       return true;
   }
   for(int j =i;j<s.size();j++){
     string s1 = s.substr(i,j-i+1);
       if(mp.find(s1)!=mp.end()){
           if(s1==s)
             return false;
           if(isCompounded(s,mp,j+1)){
               return true;
           }
       }
   }
   return   false;
}


void processInputFile(const string& file_path){
    auto start = high_resolution_clock::now();
     ios_base::sync_with_stdio(false);
     ifstream file(file_path);
       vector<string> dictionary;
       unordered_map<string,bool> mp;
        string word;
        while (getline(file, word)) {
        dictionary.push_back(word);
        mp[word] = true;
    }

    file.close();
    string largestWord = "", secondLargestWord = "";
 for(int i=0;i<dictionary.size();i++){
    
     if(isCompounded(dictionary[i],mp)){
         if(dictionary[i].size()>largestWord.size()){
             secondLargestWord = largestWord;
             largestWord = dictionary[i];
         }
         else if(dictionary[i].size()>secondLargestWord.size()){
             secondLargestWord = dictionary[i];
         }
     }
     
 }
auto stop = high_resolution_clock::now();
 auto duration = duration_cast<milliseconds>(stop - start);
 cout<<"Longest Compound Word:  "<<largestWord<<endl;
 cout<<"Second Longest Compound Word:  "<<secondLargestWord<<endl;
cout << "Time taken to process file "<< file_path << ":  " << duration.count()<<" milli seconds"<<endl<<endl;
    
}

int main (){
 string input_file_1 = "Input_01.txt";
 string input_file_2 = "Input_02.txt";
processInputFile(input_file_1);
processInputFile(input_file_2);
 
    return 0;
}