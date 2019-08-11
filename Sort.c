#include "Sort.h"
void merge_sort(Move *list,int length){
if(length<2){
return;
}
else{
Move *right,*left;
right=(Move *)malloc((length/2)*sizeof(Move));
left=(Move *)malloc((length-length/2)*sizeof(Move));
for(int a=0;a<length/2;a++)
right[a]=list[a];
for(int a=length/2;a<length;a++)
left[a-length/2]=list[a];
merge_sort(right,length/2);
merge_sort(left,length-length/2);
merge(list,right,left,length);
}
}
void merge(Move *list,Move *right,Move *left,int length){
int index_r=0,index_l=0,index=0;
while(index<length){
if(index_r==length/2){
    while(index_l<length-length/2){
      list[index]=left[index_l];
      index++;
      index_l++;
    }
    break;
}
if(index_l==length-length/2)
{
    while(index_r<length/2){
      list[index]=right[index_r];
      index++;
      index_r++;
    }
    break;
}
if(right[index_r].value<left[index_l].value){
list[index]=right[index_r];
index_r++;
}
else{
list[index]=left[index_l];
index_l++; 
}
index++;
}
}
void switch_move(Move_List *h,int a){
 
  if(a==0)
  return;
  else{
  Move t;
  t=h->list[0];
  h->list[0]=h->list[a];
  h->list[a]=t;
  }
}