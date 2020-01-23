package ceng.ceng351.labdb;

import java.util.ArrayList;
import java.lang.Math;

public class LabDB {
    int bucketSize;
    int gdepth;
    ArrayList<Bucket> hashTable;


    public LabDB(int bucketSize) {
        this.bucketSize=bucketSize;
        this.gdepth=1;
        this.hashTable = new ArrayList<Bucket>();
        Bucket b1=new Bucket(1);
        Bucket b2=new Bucket(1);
        this.hashTable.add(b1);
        this.hashTable.add(b2);
    }

    public int hashFunc(String studentID){
        int id=Integer.parseInt(studentID.substring(1));
        int i;
        int index=0;
        for(i=0; i<gdepth; i++){
            index+=(id%2)*Math.pow(2,i);
            id=id/2;
        }
        return index;
    }
    
    public void enter(String studentID) {
        if(this.search(studentID)!="-1") return;
        int index=hashFunc(studentID);
        //System.out.print(studentID+"\n");
        //System.out.print(index+"\n");
        //System.out.print(index);
        Bucket bucket = this.hashTable.get(index);
        bucket.students.add(studentID);
        Bucket nb = new Bucket(0);
        
        while(bucket.students.size()>this.bucketSize || nb.students.size()>this.bucketSize){
            if(bucket.ldepth==this.gdepth){
                resizeTable();
                nb = resizeBucket(index);
            }
            else if(bucket.ldepth<this.gdepth){
                nb = resizeBucket(index);
            }
        }
    }

    public Bucket resizeBucket(int index){
        Bucket bucket = this.hashTable.get(index);
        int power=this.gdepth-1;
        int index1=(int) (index-Math.pow(2,power));
        int index2=(int) (index+Math.pow(2,power));
        int sibindex = index1>-1?index1:index2;
        
        ArrayList<String> allStudents = new ArrayList<>();
        for(String s : bucket.students) {
            allStudents.add(s);
        }
        bucket.students.clear();
        Bucket nb = new Bucket(bucket.ldepth);
        /*
        for(int i=1; i<Math.pow(2,this.gdepth-bucket.ldepth); i++){
            sibindex-=Math.pow(2, bucket.ldepth);
            if(sibindex<0){
                sibindex+=Math.pow(2, bucket.ldepth);
                break;
            }
        }
        //sibindex+=Math.pow(2, bucket.ldepth);
        
        for(int i=1; i<Math.pow(2,this.gdepth-bucket.ldepth); i++){
            this.hashTable.set(sibindex, nb);
            sibindex+=Math.pow(2, bucket.ldepth);
        }
*/
        this.hashTable.set(sibindex, nb);
        
        for(int i=0; i<allStudents.size(); i++){
            int newindex = hashFunc(allStudents.get(i));
            Bucket newbucket = this.hashTable.get(newindex);
            newbucket.students.add(allStudents.get(i));
        }
        bucket.ldepth++;
        nb.ldepth++;
        
        return nb;
    }
    
    public void resizeTable(){
        this.gdepth++;
        int i;
        int size=this.hashTable.size();
        for(i=0; i<size; i++){
            this.hashTable.add(this.hashTable.get(i));
        }
    }
    
    public void mergeTable(){
        if(this.gdepth==1) return;
        int size=this.hashTable.size();
        for(int i=0; i<size; i++){
            if(this.hashTable.get(i).ldepth==this.gdepth && this.hashTable.get(i).students.size()!=0) return;
        }
        this.gdepth--;
        ArrayList<Bucket> newList = new ArrayList<Bucket>();
        for(int i=0; i<size/2; i++){
            newList.add(this.hashTable.get(i));
            if(this.hashTable.get(i).ldepth>this.gdepth) this.hashTable.get(i).ldepth=this.gdepth;
        }
        this.hashTable=newList;
        this.mergeTable();
    }
    
    public void copyBucket(int index, Bucket sibbucket){
        Bucket bucket = this.hashTable.get(index);
        
        int i=bucket.ldepth;
        int nobucket=1;
        
        while(i<this.gdepth){
            nobucket*=2;
            i++;
        }
        int leastindex=index;
        while(leastindex>-1){
            leastindex-=Math.pow(2, this.hashTable.get(index).ldepth);
        }
        leastindex+=Math.pow(2, this.hashTable.get(index).ldepth);
        int diff=(int) Math.pow(2, bucket.ldepth);
        for(i=0; i<nobucket; i++){
            this.hashTable.set(leastindex, sibbucket);
            leastindex+=diff;
        }
    }
    
    public void leave(String studentID) {
        if(this.search(studentID)=="-1") return;
        int index=hashFunc(studentID);
        Bucket bucket = this.hashTable.get(index);
        
        bucket.students.remove(studentID);
        if(bucket.students.isEmpty()){
            int power=bucket.ldepth-1;
            int index1=(int) (index-Math.pow(2,power));
            int index2=(int) (index+Math.pow(2,power));
            int sibindex = index1>-1?index1:index2;
            
            Bucket sibbucket = this.hashTable.get(sibindex);
            if(bucket.ldepth!=1){
                copyBucket(index, sibbucket);
                if(sibbucket.ldepth!=1) sibbucket.ldepth--;
            }
            
            if(bucket.ldepth!=1)bucket.ldepth--;
            
            this.mergeTable();
        }
    }

    public String search(String studentID) {
        int index = hashFunc(studentID);
        if(this.hashTable.get(index).students.contains(studentID)){
            String s = Integer.toBinaryString(index);
            for(int i=s.length(); i<this.gdepth; i++){
                s="0"+s;
            }
            return s;
        }
        else{
            return "-1";
        }
    }

    public String helper(int index) {
            String s = Integer.toBinaryString(index);
            for(int i=s.length(); i<this.gdepth; i++){
                s="0"+s;
            }
        return s;
    }
    
    public void printLab() {
        System.out.println("Global depth : " + this.gdepth);
        for(int i=0; i<this.hashTable.size(); i++){
            Bucket bucket = this.hashTable.get(i);
            System.out.print(helper(i)+" : [Local depth:"+bucket.ldepth+"]");
            for(int j=0; j<bucket.students.size(); j++){
                System.out.print("<"+bucket.students.get(j)+">");
            }
            System.out.println();
        }
    }
}
