#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <int,int> map_int_int; //key : integer, value integer;
    map <int,string> map_int_string; //key : integer, value string;
    map <string,int> map_string_int; //key : string, value integer;

    // operator[]
    for (int i = 1 ; i <= 5 ; i++)
        map_int_int[i] = i * 5; // (key,value) = (1,5) , (2,10) , (3,15) , (4,20) , (5,25)

    map_int_string[1] = "one";
    map_int_string[2] = "two";
    map_int_string[3] = "three"; // (key,value) = (1,"one") , (2,"two") , (3,"three")

    // insert()
    for (auto it = map_int_string.begin(); it != map_int_string.end(); ++it){
        map_string_int.insert(make_pair(it->second, it->first)); //(key,value) = ("one",1) , ("two",2) , ("three",3)
    } 
       
    // print map <string,int>
    cout << "\nmap_string_int's content : \n";
    cout << "\nkey\telement\n";
    for(auto it = map_string_int.begin(); it != map_string_int.end(); ++it){
        cout << it->first << '\t' << it->second << endl;
    }
    puts("");

    // erase()
    map_string_int.erase("one");

    // print map <string,int>
    cout << "map_string_int's content after erasing key = \"one\" : \n";
    cout << "\nkey\telement\n";
    for(auto it = map_string_int.begin(); it != map_string_int.end(); ++it){
        cout << it->first << '\t' << it->second << endl;
    }
    puts("");

    // size()
    cout << "map_int_string's size : " << map_int_string.size() << endl;

    // clear
    map_int_string.clear();
    cout << "map_int_string's size after clearing : " << map_int_string.size() << endl;
    puts("");

    // find()
    for (int i=1 ; i<=3 ; i++){
        (map_int_int.find(i) != map_int_int.end())? 
        cout << "key " << i << " is found -> value : " << map_int_int[i] << endl : cout << "key " << i << " is not in the map" << endl;
    }

    // count()
    for(int i=4; i<=7; i++){
        (map_int_int.count(i))? 
        cout << "key " << i << " is found -> value : " << map_int_int[i] << endl : cout << "key " << i << " is not in the map" << endl;
    }
    puts("");

    return 0;
}