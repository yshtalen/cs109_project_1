//function that takes in string command and output String vector
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> parse(string in_line){
        string command_in = in_line;
        vector<string> params;
        string command;
        string param;
        int place = 0;

        //create command string
        while(command_in[place]!=' ' && isupper(command_in[place])){
                command+=command_in[place];
                place++;
        }
        //insert it into param vector
        params.insert(params.begin(), command);
        command.clear();
        //skip white space
        place++;
        //create string for each parameter after command separated by comma

        //do while not at end of string reach end of string
        do{
                //until reach comma or end of instruction string
                while(command_in[place]!=',' && place<command_in.length()){
                        param+=command_in[place];
                        place++;
                }
                params.insert(params.end(), param);
                param.clear();
                //skip comma
                place++;
        }while(place<command_in.length());

        return  params;
}
