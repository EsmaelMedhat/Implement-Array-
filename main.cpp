#include<iostream>
using namespace std;
template<class type>
class Array{
public:
Array(int array_size){
size=array_size;
length=0;
data=new type[size];
}
~Array(){
delete []data;
}
void fill(){
int numberOfItem;
cout<<"how many item you want to fill";
cin>>numberOfItem;
try {
if(numberOfItem>size)
throw exception();
else{
cout<<" Add your item\n";
for(int i=0;i<numberOfItem;i++){
cout<<"item  "<<i+1<<":";cin>>data[i];
length++;
}
}
}
catch(exception error){
cout<<endl<<error.what()<<endl;
fill();
}
}
void display(){
cout<<"\n*****all element*******\n";
for(int i=0;i<length;i++){
cout<<"item  "<<i+1<<":   "<<data[i]<<endl;
}
}
int get_length(){return length;}
int get_size(){return size;}
string search(type value){
for(int i=0;i<length;i++){
if(data[i]==value)
return "Found in index "+to_string(i);
}
return "Not found";
}
void append(type new_data){
if(length<size){
  data[length]=new_data;
length++;
}
else cout<<"full array\n";
}
void insert(int index,type newItem){
if(index>=0&&index<size)
{
for(int i=length;i>index;i--)
{
data[i]=data[i-1];
}
data[index]=newItem;
length++;
}
}
void deletE(int index){
if(index>=0&&index<size)
{
for(int i=index;i<length-1;i++)
{
data[i]=data[i+1];
}
length--;
}
}
void enlarge(int newSize) {
if(newSize>size){
type *old=data;
data=new type[newSize];
size=newSize;
for(int i=0;i<length;i++){
data[i]=old[i];
}
delete []old;
}
}
void merge(Array other){
type *old=data;
int newSize=size+other.get_size();
data=new type[newSize];
size=newSize;
int i;
for(i=0;i<length;i++){
data[i]=old[i];
}
delete []old;
int j=i;
for(int i=0;i<other.get_length();i++)
{
data[j++]=other.data[i];
length++;
}
}
void reverse(){
type*old=data;
data=new type[size];
int m=0;
for(int i=length-1;i>=0;i--){
data[i]=old[m];
m++;
}
delete []old;
}
void insert_first(type new_item){
if(length!=0&&length<size){
for(int i=length;i>=0;i--)
{
  data[i]=data[i-1];
}
data[0]=new_item;
length++;
}
else{
    data[0]=new_item;
length++;
}
}
void delete_first(){
if(length>0){
for(int i=0;i<length-1;i++){
 data[i]=data[i+1];
}
length--;
}
else{
    cout<<"array is empty";
}
}
void delete_end(){
if(length>0){
length--;
}
else{
cout<<"array is empty\n";
}
}
type get_first(){
return data[0];
}
type get_last(){
return data[length-1];
}
private:
int size;
int length;
type *data;
};
int main() {
return 0;
}
