#include<iostream>
#include<string>
using namespace std;

//Target interface expected by the client
class IReports {
    public:
    //now takes the raw data string and returns json
    virtual string getJsonData(const string& data)=0;
    virtual ~IReports(){};
};
//Adaptee provides the XML data from a raw input
class XmlDataprovider{
    public:
    //expect data in "name::id" format(e.g. "Alice:42")
    string getXmlData(const string& data){
        size_t sep=data.find(':');
        string name=data.substr(0,sep);
        string id =data.substr(sep+1);
        return "<user>"
        "<name>" + name + "</name>"
        "<id>" + id +  "</id>"
        "</user>";
    }
};
//adapter:implements ireports by converting xml->json
class XmlDataprovideradapter:public IReports{
    private:
    XmlDataprovider* xmlprovider;
    public:
    XmlDataprovideradapter(XmlDataprovider* provider):xmlprovider(provider){}
    string getJsonData(const string& data)override{
        //get xml from the adaptee
        string xml=xmlprovider->getXmlData(data);
        //naively parse out <name> and<id> values
        size_t startname=xml.find("<name>")+6;
        size_t endName =xml.find("</name>");
        string name=xml.substr(startname,endName-startname);
        size_t startId =xml.find("<id>")+4;
        size_t endId =xml.find("</id>");
        string id=xml.substr(startId,endId-startId);

        //build and return json
        return "{\"name\":\"" + name + "\",\"id\":\"" + id + "\"}";
    }
};

class Client{
    public:
    void getReport (IReports * report,string rawdata ){
        cout<<"Processed JSON: "<<report->getJsonData(rawdata)<<endl;

    }
};
 int main(){
    XmlDataprovider* xmlprov=new XmlDataprovider();
    IReports * adapter=new XmlDataprovideradapter(xmlprov);
    string rawdata="Lavanya Nagle : 26";
    Client* client=new Client();
    client->getReport(adapter,rawdata);
    delete client;
    delete adapter;
    delete xmlprov;
    return 0;
 }