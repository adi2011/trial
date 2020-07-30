struct Workshop{
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops{
    int n;
    vector<Workshop> arr;
};
Available_Workshops* initialize (int start_time[], int duration[], int n){    
    Available_Workshops* aw=new Available_Workshops;
    aw->n=n;
    for(int i=0;i<n;i++){        
        Workshop temp;
        temp.start_time= start_time[i];
        temp.duration= duration[i];
        temp.end_time= start_time[i]+duration[i];
        aw->arr.push_back(temp);
    }
    return aw;
}
bool operator <(Workshop& ws,Workshop& w){
    return ws.duration<w.duration;
}
int CalculateMaxWorkshops(Available_Workshops* ptr){
    int count=0;       
    sort(ptr->arr.begin(),ptr->arr.end());
    for(auto i=ptr->arr.begin();i<ptr->arr.end();i++){
        count++;        
        for(auto j=i+1;j<ptr->arr.end();j++){     

            if((i->end_time < j->end_time) && (i->end_time > j->start_time)){
                ptr->arr.erase(j);
            }else if(((i->start_time < j->end_time)&&(i->start_time > j->start_time))||(i->start_time == j->start_time)){
                ptr->arr.erase(j);                
            }
            
        }
        
    }
    return count;
}