#include<vector>
#include<iostream>
#include <fstream>
using namespace std;



class DocumentEditor{
private:
vector<string>DocumentElements;
string RenderedDocument;
public:

//a method to add text
void addtext(string text){
    DocumentElements.push_back(text);
}
//a method to add image
void addImage(string ImgPath){
    DocumentElements.push_back(ImgPath);
}

// a method to render document-this will loop through the entire document,render it and then return the output in string form
string RenderDocument(){
    if(RenderedDocument.empty()){
        string result;
        for(auto element:DocumentElements){
            if(element.size()>4 && (element.substr(element.size() -4)==".jpg"||
            element.substr(element.size()-4)==".png")){
                result+="[Image:"+element+']'+"\n";
            }else{
                result+=element +"\n";
            }
        }
        RenderedDocument=result;
    }
    return RenderedDocument;
}
//a method to savetofile
void saveToFile(){
    ofstream file("document.txt");
    if(file.is_open()){
        file<<RenderDocument();
        file.close();
        cout<<"Document saved to document.txt"<<endl;
    }else{
        cout<<"Error Unable to open file for writing"<<endl;
    }
    //we can also use a try catch block
}
};
int main(){
    DocumentEditor editor;
    editor.addtext("Hello,World!");
    editor.addImage("lockscreem,jpg");
    editor.addtext("It is a word document");
    cout<<editor.RenderDocument()<<endl;
    editor.saveToFile();
    return 0;
}













