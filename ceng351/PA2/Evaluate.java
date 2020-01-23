package ceng.ceng351.labdb;

import java.io.*;
import java.util.Objects;
import java.util.Scanner;

public class Evaluate {

    static void CorrectnessCheck(int testId, String testName, ByteArrayOutputStream out)
    {
        String res = out.toString();
        res = res.replaceAll("\r", ""); // windows line endings reduced
        // read correct output
        String test = readFile("outputs/output" + testId + ".txt");
        // correctness check
        if(Objects.equals(test, res))
        {
            System.err.println(testName + " Passed!");
            counter++;
        }
        else
        {
            System.err.println(testName + " Failed!");
        }
        // dump results
        if(outputDir.equals("")) // no path has been given
            return;
        try {
            writeFile(res, outputDir + testId + ".txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void Test1()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));

            LabDB labdb = new LabDB(4);
            labdb.printLab();
            CorrectnessCheck(1, "Sample Test 1", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test2()
    {
        LabDB labdb = new LabDB(4);
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));

            labdb.enter("e4");
            labdb.printLab();
            CorrectnessCheck(2, "Sample Test 2", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test3()
    {
        LabDB labdb = new LabDB(4);
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));

            labdb.enter("e4");
            labdb.enter("e12");
            labdb.enter("e32");
            labdb.enter("e16");
            labdb.enter("e1");
            labdb.enter("e5");
            labdb.enter("e21");
            labdb.enter("e10");
            labdb.enter("e15");
            labdb.enter("e7");
            labdb.enter("e19");
            labdb.printLab();
            CorrectnessCheck(3, "Sample Test 3", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test4()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));

            LabDB labdb = new LabDB(4);
            labdb.enter("e4");
            labdb.enter("e12");
            labdb.enter("e32");
            labdb.enter("e16");
            labdb.enter("e1");
            labdb.enter("e5");
            labdb.enter("e21");
            labdb.enter("e10");
            labdb.enter("e15");
            labdb.enter("e7");
            labdb.enter("e19");
            labdb.enter("e13");
            labdb.enter("e20");
            labdb.enter("e9");
            labdb.printLab();
            CorrectnessCheck(4, "Sample Test 4", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test5()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labdb = new LabDB(4);
            labdb.enter("e4");
            labdb.enter("e12");
            labdb.enter("e32");
            labdb.enter("e16");
            labdb.enter("e1");
            labdb.enter("e5");
            labdb.enter("e21");
            labdb.enter("e10");
            labdb.enter("e15");
            labdb.enter("e7");
            labdb.enter("e19");
            labdb.enter("e13");
            labdb.enter("e20");
            labdb.enter("e9");
            System.out.println(labdb.search("e20"));
            System.out.println(labdb.search("e21212121"));
            CorrectnessCheck(5, "Sample Test 5", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test6()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));

            LabDB labdb = new LabDB(4);
            labdb.enter("e4");
            labdb.enter("e12");
            labdb.enter("e32");
            labdb.enter("e16");
            labdb.enter("e1");
            labdb.enter("e5");
            labdb.enter("e21");
            labdb.enter("e10");
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
            CorrectnessCheck(6, "Sample Test 6", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test7()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(1);
            labDB.enter("e1");
            labDB.enter("e16");
            labDB.enter("e2");
            labDB.enter("e4");
            labDB.enter("e8");
            labDB.printLab();
            CorrectnessCheck(7, "Test 7: Recursive splits", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test8()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(1);
            labDB.enter("e16");
            labDB.enter("e32");
            labDB.leave("e16");
            labDB.printLab();
            labDB.leave("e32");
            labDB.printLab();
            CorrectnessCheck(8, "Test 8: Recursive merges", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test9()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(1);
            labDB.leave("e1");
            labDB.printLab();
            labDB.enter("e1");
            labDB.leave("e1");
            labDB.printLab();
            CorrectnessCheck(9, "Test 9: Leave before enter / Do not merge when global depth is 1", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test10()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(2);
            labDB.enter("e55");
            labDB.enter("e55");
            labDB.printLab();
            CorrectnessCheck(10, "Test 10: Enter more than once", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test11()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(4);
            labDB.enter("e128");
            labDB.enter("e256");
            labDB.enter("e2");
            labDB.enter("e19");
            labDB.enter("e10");
            labDB.enter("e65");
            labDB.enter("e64");
            labDB.enter("e32");
            labDB.enter("e16");
            labDB.enter("e1024");
            labDB.enter("e512");
            labDB.enter("e199");
            labDB.enter("e8");
            labDB.enter("e19");
            labDB.printLab();
            CorrectnessCheck(11, "Test 11", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test12()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(4);
            labDB.enter("e128");
            labDB.enter("e256");
            labDB.enter("e2");
            labDB.leave("e2");
            labDB.enter("e19");
            labDB.enter("e10");
            labDB.enter("e65");
            labDB.enter("e64");
            labDB.enter("e32");
            labDB.leave("e32");
            labDB.enter("e16");
            labDB.enter("e1024");
            labDB.enter("e512");
            labDB.enter("e199");
            labDB.enter("e8");
            labDB.enter("e19");
            labDB.leave("e256");
            labDB.leave("e16");
            labDB.leave("e1024");
            labDB.leave("e512");
            labDB.leave("e199");
            labDB.leave("e128");
            labDB.leave("e65");
            labDB.leave("e10");
            labDB.leave("e8");
            labDB.printLab();
            labDB.leave("e64");
            labDB.printLab();
            CorrectnessCheck(12, "Test 12", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test13()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(8);
            for (int i = 2; i <= 256; i+=2) {
                labDB.enter("e" + i);
            }
            labDB.printLab();
            CorrectnessCheck(13, "Test 13", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test14()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));
            LabDB labDB = new LabDB(8);
            for (int i = 2; i <= 256; i+=2) {
                labDB.enter("e" + i);
            }
            int i;
            for (i = 2; i <= 128; i+=2) {
                labDB.leave("e" + i);
            }
            labDB.printLab();
            for (; i <= 256; i+=2) {
                labDB.leave("e" + i);
            }
            labDB.printLab();
            CorrectnessCheck(14, "Test 14", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void Test15()
    {
        try {
            ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            System.setOut(new java.io.PrintStream(out));

            LabDB labdb = new LabDB(1);
            labdb.enter("e0");
            labdb.printLab();
            labdb.enter("e1");
            labdb.printLab();
            labdb.enter("e8");
            labdb.printLab();
            labdb.enter("e5");
            labdb.printLab();
            CorrectnessCheck(15, "Test 15", out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static int counter = 0;
    // IMPORTANT if you want to see your outputs change outputDir below
    // ex: src/ceng/ceng351/labdb/my_outputs/
    private static String outputDir = "";

    public static void main(String[] args)
    {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
        Test8();
        Test9();
        Test10();
        Test11();
        Test12();
        Test13();
        Test14();
        Test15();
        // Do not forget to change this when you add new test cases
        int testCount = 15;
        System.err.println("Passed " + counter + "/" + testCount);
    }

    private static String readFile(String filePath)
    {
        //Creating an InputStream object
        InputStream inputStream = LabDB.class.getResourceAsStream(filePath);
        //Creating a Scanner object
        Scanner sc = new Scanner(inputStream);
        //Reading line by line from scanner to StringBuffer
        StringBuilder sb = new StringBuilder();
        while(sc.hasNext()){
            sb.append(sc.nextLine()).append("\n");
        }
        try {
            inputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return sb.toString();
    }

    public static void writeFile(String content, String filePath) throws IOException {
        File file = new File(filePath);
        file.createNewFile();
        FileOutputStream fOut = new FileOutputStream(file, false);
        fOut.write(content.getBytes());
        fOut.close();
    }

}

