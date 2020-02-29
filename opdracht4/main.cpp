#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string> 
#include <iterator>
#include <map>
#include <utility>

//Function that fills a vector with the characters of a file
std::vector<char> fillVector(std::vector<char> &v, const std::string &filename){
    std::ifstream file(filename);
    file >> std::noskipws; 
    std::copy(std::istream_iterator<char>(file), {}, std::back_inserter(v));
    file.close();
    return v;
} 

//Prints the size of the vector 
void printSize(std::vector<char> &v){
    std::cout << "The file contains " << v.size() << " characters." << std::endl;
}

//Counts the \n of the vector 
void countLines(std::vector<char> &v){
    int result = std::count(v.begin(), v.end(), '\n');
    std::cout << "The file contains " << result << " lines." << std::endl;
}


void countAlphabeticCharacters(std::vector<char> &v){
    int result = std::count_if(v.begin(), v.end(), [](char k ){return isalpha(k);} );
    std::cout << "The file contains " << result << " alphabetic characters." << std::endl;
}

std::vector<char> convertToLowercase(std::vector<char> &v){
    std::transform(v.begin(), v.end(), v.begin(), ::tolower);
    return v;
}

void countLetterOccurences(std::vector<char>  &v){
    char list[] = "abcdefghijklmnopqrstuvwxyz";
    std::for_each(std::begin(list), std::end(list) -1, 
    [&](char k ){std::cout << "The letter " << k << " occures " << std::count(v.begin(), v.end(), k)  << "times." << std::endl;});
}

void mostOcurringWords(std::vector<char> &v){

    std::vector<std::string> s; 
    std::string temp = "";
    std::for_each(v.begin(), v.end(), [&](char k){ 
        if(isalpha(k)){
            temp += k;
        }
        else if(!isalpha(k) && !temp.empty()){
            s.push_back(temp);
            temp = "";
        }});
        

    std::map<std::string, int> m;
    std::for_each(s.begin(), s.end(), [&](std::string k){
        if(m.count(k) == 0){
            m.insert({k, 1});
        }
        else{
            m.at(k)++;
        }
    });

    std::map<int, std::string> finalMap;
    std::for_each(m.begin(), m.end(), [&](std::pair<std::string, int> p){
       finalMap.insert({p.second, p.first});
    });
    std::map<int, std::string>::reverse_iterator it = finalMap.rend();
    std::advance(it, 11);

    int count = 0;
    std::for_each(finalMap.rbegin(), it, [&](std::pair<int, std::string> p){
        count++;
        std::cout << "Most ocurred word at place " << count << " is the word "<< p.second << " with a count of " << p.first << std::endl;
    });
}

int main(){
    std::vector<char> vec;
    vec = fillVector(vec, "kingJames.txt");
    printSize(vec);
    countLines(vec);
    countAlphabeticCharacters(vec);
    convertToLowercase(vec);
    countLetterOccurences(vec);
    mostOcurringWords(vec);
    return 0;
}