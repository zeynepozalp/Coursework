`timescale 1ns / 1ps

module df(
    input d,
    input f,
    input clk,
    output reg q
    );

    initial begin
        q = 0;
    end

    // write your code here

    always@(posedge clk)
      begin
       if(d==0 && f==0)
          q<=1;
       else if(d==0 && f==1)
          q<=q;
       else if(d==1 && f==0)
          q<=0;
       else q<=~q;
      end

endmodule

module icplusplus(
    input d0,
    input f0,
    input d1,
    input f1,
    input clk,
    output q0,
    output q1,
    output y
    );

    df df0(d0,f0,clk,q0);
    df df1(d1,f1,clk,q1);

    assign y = q0 ~^ q1;
endmodule
