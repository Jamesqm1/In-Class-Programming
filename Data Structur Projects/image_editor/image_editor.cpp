/*
        image_editor.cpp
        
        Method implementations for the image_editor class.

        author: C. Painter-Wakefield

        last modified: 1/15/2018
*/

#include <utility>

#include "image_editor.h"



using namespace std;


bool image_editor::load(istream& in) {
    // test magic string
    string magic;
    in >> magic;
    if (magic != "P3") return false;

    // TODO: get columns, rows, ensure valid
    in>>cols;
    in>>rows;
    if(cols<1 || rows<1){
        return false;
    }
    // TODO: get and discard color depth
    in>>color_depth;
    if(color_depth!=255){
        return false;
    }
    // TODO: initialize your image storage data structure
    pixels = {}; // vector of all pixels
    // TODO: get image data from input stream into your data structure
    
    while(!in.eof()){
        int n;
        in>>n;
        pixels.push_back(n);
    }
    
    return true;
}

void image_editor::save(ostream& out) {
    out << "P3" << endl;
    out << cols << " " << rows << endl;
    out << color_depth << endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            for(int k =0;k<3;k++){
                out << pixels[i*cols*3+j*3+k] << " ";
            }
        }
        out<<endl;
    }
}

int image_editor::get_rows() {
    // TODO: return the correct # of rows
    return rows;
}

int image_editor::get_columns() {
    // TODO: return the correct # of columns
    return cols;
}
int image_editor::get_red(int row, int col) {
    // TODO: return the actual pixelsel red value
    return pixels.at(row*cols*3+col*3);
}

int image_editor::get_green(int row, int col) {
    // TODO: return the actual pixelsel green value
    return pixels.at(row*cols*3+col*3+1);
}

int image_editor::get_blue(int row, int col) {
    // TODO: return the actual pixelsel blue value
    return pixels.at(row*cols*3+col*3+2);
}

void image_editor::apply_effect(int action_index) {
    enum action a = (enum action)action_index;

    // TODO: fill out this method
    if (a == GRAYSCALE) {
        greyscale();
    }
    else if (a == NEGATE_RED) {
        negate(0);
    }
    else if (a == NEGATE_GREEN) {
        negate(1);
    }
    else if (a == NEGATE_BLUE) {
        negate(2);
    }
    else if (a == FLATTEN_RED) {
        flatten(0);
    }
    else if (a == FLATTEN_GREEN) {
        flatten(1);
    }
    else if (a == FLATTEN_BLUE) {
        flatten(2);
    }
    else if (a == EXTREME_CONTRAST){
        excontrast();
    }
    else if (a == FLIP_HORIZONTAL){
        flip(true);
    }
    else if (a== FLIP_VERTICAL){
        flip(false);
    }
    else if (a == RANDOM){
        random();
    }
    else if(a==PATTERN){
        cout << "Enter 3 numbers :: ";
        int a,b,c;
        cin >> a >> b >> c;
        pattern(a,b,c);
    }
}
void image_editor::greyscale(){
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            int avg =0;
            for(int k=0;k<3;k++){
                avg = avg + pixels[i*cols*3+j*3+k];
            }
            avg = avg/3;
            for(int k=0;k<3;k++){
                pixels[i*cols*3+j*3+k] = avg;
            }
        }
    }
}
void image_editor::negate(int rgb){ // 0 = red, 1 = green, 2 = blue
    
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            pixels[i*cols*3+j*3+rgb] = 255 -pixels[i*cols*3+j*3+rgb];
        }
    }
}
void image_editor::flatten(int rgb){ // 0 = red, 1 = green, 2 = blue
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            pixels[i*cols*3+j*3+rgb] = 0;
        }
    }
}

void image_editor::excontrast(){
     for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            int sum =0;
            for(int k=0;k<3;k++){
                sum = sum + pixels[i*cols*3+j*3+k];
            }
            if(sum>=255*3/2){
                sum = 255;
            }
            else{
                sum=0;
            }
            for(int k=0;k<3;k++){
                pixels[i*cols*3+j*3+k] = sum;
            }
        }
    }
}
void image_editor::flip(bool horizontal){
    vector<int> temp = pixels;
    if(horizontal){
        for(int i =0;i<rows;i++){
            for(int j=0;j<cols;j++){
                for(int k =0;k<3;k++){
                    pixels[i*cols*3+j*3+k]=temp[i*cols*3+(cols-j-1)*3+k];
                }
            }
        }
    }
    else{
        for(int i =0;i<rows;i++){
            for(int j=0;j<cols;j++){
                for(int k =0;k<3;k++){
                    pixels[i*cols*3+j*3+k]=temp[(rows-i-1)*cols*3+j*3+k];
                }
            }
        }
    }
}
void image_editor::random(){
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            for(int k =0;k<3;k++){
                pixels[i*cols*3+j*3+k]= rand()%255 +1;
            }
        }
    }
}

void image_editor::pattern(int a,int b,int c){
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            for(int k =0;k<3;k++){
                pixels[i*cols*3+j*3+k]= ((((i*a)/b*k)^j^c)*13)%255 +1;
            }
        }
    }
}


 
