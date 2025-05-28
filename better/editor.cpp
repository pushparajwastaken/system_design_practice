#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

//Abstraction for Document Elements
class DocumentElement{
    public:
    virtual string render()=0;
};
//Concrete implementation for text elements
class TextElement : public DocumentElement{
    private:
    string text;
    public:
    TextElement(string text){
        this->text=text;
    }
    string render()override{
        return text;
    }
};
//Concrete implementation for image elements
class ImageElement:public DocumentElement{
    private:
    string imagePath;
    public:
    ImageElement(string imagePath){
        this->imagePath=imagePath;
    }
    string render()override{
        return "Image: "+imagePath;
    }
};
//Newline element represents a line break in the document
class NewlineElement : public DocumentElement{
    public:
    string render()override{
        return"\n";
    }
}
;
class TextSpaceElement:public DocumentElement{
    public:
    string render()override{
        return"\t";
    }
};

//Document class responsible for holding a collection of elements
class Document{
    private:
    //why use pointers here? because DocumentElement is an abstract base class (has a pure virtual method), we cannot create objects of it directly.
    vector<DocumentElement*> documentElements;
    public:
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }
    //Renders the document by concatenating the render output of all elements
    string render(){
        string result;
        for(auto element:documentElements){
            result+=element->render();
        }
        return result;
    }
};
//Persistance interface 
class Persistance{
    public:
    virtual void save(string data)=0;
};
//filestorage implementation of Persistance
class FileStorage:public Persistance{
    public:
    void save(string data )override{
        ofstream outfile("document.txt");
        if(outfile){
            outfile<<data;
            outfile.close();
            cout<<""<<endl;
            cout<<"Document saved to document.txt"<<endl;
        }else{
            cout<<"Error: Unable  to open file for writing"<<endl;
        }
    }
};
//Placeholder DBStorage implementation 
class DBStorage:public Persistance{
    public:
    void save (string data)override{
        //save to db
    }
};

class DocumentEditor{
    private:
    Document* document;
    Persistance* storage;
    string renderedDocument;
    public:
    DocumentEditor(Document* document, Persistance* storage){
        this->document=document;
        this->storage=storage;
    }
    void addText(string text){
        document->addElement(new TextElement(text));
    }
    void addImage(string imagepath){
        document->addElement(new ImageElement(imagepath));
    }
    void addNewLine(){
        document->addElement(new NewlineElement());
    }
    void addTabSpace(){
        document->addElement(new TextSpaceElement());
    }
    string renderdocument(){
        if(renderedDocument.empty()){
            renderedDocument=document->render();
        }
        return renderedDocument;
    }
    void savedocument(){
        storage->save(renderdocument());
    }
};