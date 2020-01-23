package ceng.ceng351.labdb;

public class Evaluate1 {

    public static void main(String[] args) {
        LabDB labdb = new LabDB(4);
        try {

            labdb.enter("e4");
            labdb.enter("e12");
            labdb.enter("e32");
            labdb.enter("e16");
            labdb.enter("e1");
            labdb.enter("e5");
            labdb.enter("e21");
            labdb.printLab();
            labdb.enter("e12");
            labdb.printLab();
            labdb.enter("e12");
            labdb.printLab();
            labdb.enter("e15");
            labdb.enter("e7");
            labdb.enter("e19");
            labdb.enter("e13");
            labdb.enter("e20");
            labdb.enter("e9");
            labdb.leave("e32");
            labdb.leave("e16");
            labdb.leave("e10");
            labdb.leave("e9");
            labdb.leave("e1");
            labdb.leave("e4");
            labdb.leave("e12");
            labdb.leave("e20");
            labdb.leave("e5");
            labdb.leave("e21");
            labdb.leave("e13");
            labdb.printLab();

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
