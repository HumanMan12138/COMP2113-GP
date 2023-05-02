
#include <iostream>
#include <fstream>
#include <string>
#include "head.h"
#include "game.h"
using namespace std;

    //Initialize the game
struct Infor{
    int initialmoney,pass,state;
    bool pledge;

    };

void saveInfor(const Infor& I, const string& filename) {
    ofstream file(filename, ios::binary);
    file.write(reinterpret_cast<const char*>(&I), sizeof(I));
    file.close();

}

Infor loadInfor(const string& filename) {
    Infor I;
    ifstream file(filename, ios::binary);
    file.read(reinterpret_cast<char*>(&I), sizeof(I));
    file.close();
    return I;
}

int main() {
    string sl;
    Infor I;
    cout<<"Load the last game or start a new game"<<endl;
    cout<<endl;
    cout<<"Please enter Load or New"<<endl;
    cin>>sl;
    while (sl!="Load" && sl!="New" && sl!="load" && sl!="new" ){
        cout<<"Invalid input, please enter again"<<endl;
        cin>>sl;
    }
    if (sl=="Load" || sl=="load"){
        I=loadInfor("save.dat");
    }
    else if (sl=="New" || sl=="new"){
    I.initialmoney=1000;
    I.pass=1;
    I.pledge=false;
    I.state=0;
    }
    cout<<endl;
    string line,input;
    //Start of the game


    while (I.state!=6){

    //Initial
    if(I.state==0){
       ifstream Initial("Initial.txt");
       while (getline(Initial, line)) {
       while (getline(cin, input)) {
        if (input == "") {
            cout<<line<<endl;
            break;
        }
       }
    }
    I.state++;
    Initial.close();
    }

    //Game1
    if(I.state==1){

    ifstream Bffs("Bffs.txt");
    while (getline(Bffs, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }


    }
    }
    Bffs.close();


    //Game1 to be filled (Blakcjack)
    I.initialmoney=blackJack(I.initialmoney);


    //End1.1
    if (I.initialmoney>0){
    ifstream Bffse1("Bffse1.txt");
    while (getline(Bffse1, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    I.state++;
    Bffse1.close();
    }

    //End1.2
    else if (I.initialmoney<=0){
    ifstream Bffse2("Bffse2.txt");
    while (getline(Bffse2, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    I.state++;
    Bffse2.close();
    exit(0);
    }
    }

    //Game2 to be filled (Martingale)

    if(I.state==2){

    ifstream Bffs2("Bffs2.txt");
    while (getline(Bffs2, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }


    }
    }
    Bffs2.close();


    //Game2
    I.initialmoney=Casino(I.initialmoney);

    //End2.1
    if (I.initialmoney>1500){
    ifstream Bffs2e1("Bffs2e1.txt");
    while (getline(Bffs2e1, line)) {
        while (getline(cin, input)) {
            if (input == "") {

                cout<<line<<endl;
                break;
            }
        }
    }
    I.initialmoney=I.initialmoney-1500;
    I.state++;
    I.pledge=true;
    Bffs2e1.close();
    }

    //End2.2
    else if (I.initialmoney<1500){
    ifstream Bffs2e2("Bffs2e2.txt");
    while (getline(Bffs2e2, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    Bffs2e2.close();
    I.state++;
    }
    cout<<endl;
    }

    //Game3
    if(I.state==3){
    cout<<"A strong light flashed, Tarnished sees the second statue. He decides to rest for a while or continue the journey."<<endl;
    cout<<endl;
    cout<<"Please enter Save or Exit"<<endl;
    string choice;
    cin>>choice;
    while (choice!="Save" && choice!="Exit" && choice!="save" && choice!="exit"){
        cout<<"Invalid input, please enter again"<<endl;
        cin>>choice;
    }
    cout<<endl;
    if (choice=="Save" || choice=="save"){
        saveInfor(I, "save.dat");
    }
    else if(choice=="Exit" || choice=="exit"){
        saveInfor(I, "save.dat");
        exit(0);
    }
    ifstream Bffs3("Bffs3.txt");
    while (getline(Bffs3, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }


    }
    }
    Bffs3.close();


    //Game3 to be filled (Battleplane)
    int output3=battleplane();
    cout<<endl;

    //End3.1
    if (output3==1){
    ifstream Bffs3e1("Bffs3e1.txt");

    while (getline(Bffs3e1, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    I.state++;
    Bffs3e1.close();
    }

    //End3.2
    else if (output3==0){
    ifstream Bffs3e2("Bffs3e2.txt");
    while (getline(Bffs3e2, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    Bffs3e2.close();
    if (I.pledge==true){
        I.pledge=0;
        continue;
    }
    else{
        exit(0);
    }
    }
    }

    //Game 4
    if(I.state==4){
    cout<<endl;

    ifstream Bffs4("Bffs4.txt");
    while (getline(Bffs4, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }


    }
    }
    Bffs4.close();


    //Game4 to be filled (Martingale)
    I.initialmoney=Casino(I.initialmoney);
    int output4=1;

    //End4.1
    if (output4==1){
    ifstream Bffs4e1("Bffs4e1.txt");
    while (getline(Bffs4e1, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    I.state++;
    Bffs4e1.close();
    }


    }
    //Game 5
    if(I.state==5){
    cout<<endl;
    cout<<"Tarnished could see a door behind the third statue, the sunlight draws the outline of it. That shall be the end of this journey. Tarnished decides to rest for a while or continue. "<<endl;
    cout<<endl;
    cout<<"Please enter Save or Exit"<<endl;
    string choice;
    cin>>choice;
    while (choice!="Save" && choice!="Exit" && choice!="save" && choice!="exit"){
        cout<<"Invalid input, please enter again"<<endl;
        cin>>choice;
    }
    cout<<endl;
    if (choice=="Exit" || choice=="exit"){
        saveInfor(I, "save.dat");
        exit(0);
    }
    else if (choice=="Save" || choice=="save"){
        saveInfor(I, "save.dat");
    }
    ifstream Bffs5("Bffs5.txt");
    while (getline(Bffs5, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }


    }
    }
    Bffs5.close();


    //Game5 to be filled (Riddles)
    int output5=riddles(I.initialmoney);

    //End5.1
    if (output5==1){
    ifstream Bffs5e1("Bffs5e1.txt");
    while (getline(Bffs5e1, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    I.state++;
    Bffs5e1.close();
    exit(0);
    }
    //End5.2
    else if (output5==0){
    ifstream Bffs5e2("Bffs5e2.txt");
    while (getline(Bffs5e2, line)) {
      while (getline(cin, input)) {
        if (input == "") {

            cout<<line<<endl;
            break;
        }
    }
    }
    Bffs5e2.close();
    exit(0);
    }


    }

    }

    return 0;
}
