/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ceng.ceng351.labdb;

import java.util.ArrayList;

/**
 *
 * @author ZEYNEP
 */
public class Bucket {
    int ldepth;
    ArrayList<String> students;
    
    public Bucket(int ldepth){
        this.ldepth=ldepth;
        ArrayList<String> s = new ArrayList<>();
        this.students=s;
    }
    
    public Bucket(Bucket that){
        this(that.ldepth);
        this.students=new ArrayList<>();
        that.students.forEach((s) -> {
            this.students.add(s);
        });
    }
}
