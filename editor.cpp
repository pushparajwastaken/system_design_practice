#include<vector>
#include<iostream>
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

};

















int main(){
    return 0;
}