`timescale 1ns / 1ps

module Board232 (
    input mclk,
    input [3:0] btn,
    input [7:0] sw,
    output [7:0] led,
    output reg [6:0] seg,
    output reg [3:0] an,
    output reg dp,
    output [2:1] OutBlue,
    output [2:0] OutGreen,
    output [2:0] OutRed,
    output HS,
    output VS
    );
    // assign dp = 1'b1;
    // assign led[7:0]=0;

    initial begin
          seg[6:0] = 7'b0000000;
        an[3:0]  = 4'b1111; // 7 segmentte hangi yerler yanacak
        
     end
 
    
    wire  [3:0] n_cars_in_gasoline_queue;
    wire  [3:0] n_cars_in_diesel_queue;
    wire  [7:0] total_gasoline_needed;
    wire  [7:0] total_diesel_needed;
    
    reg [26:0] mclk_counter;
    
    initial mclk_counter<= 0;
    always @(posedge mclk) mclk_counter = mclk_counter+1;   
    reg clk;
    initial clk = 1'b0;
    
    always@(btn[3] or mclk_counter[23] or btn[0]) 
    begin
        if(btn[3]) 
            clk = mclk_counter[23];
        else 
            clk = btn[0];
        end
            
    
    lab4_2 HH(
        sw[1:0],                        // mode,
        sw[7:5],                        // n_gasoline_pump,
        sw[4:2],                        // n_diesel_pump,
        sw[7:4],                        // fuel_amount,
        sw[3],                          // fuel_type
        clk,                            // CLK
        led[7:2],                       // pump_status
        led[1],                         // is_gasoline_queue_not_full
        led[0],                         // is_diesel_queue_not_full
        n_cars_in_gasoline_queue,       // to represent max 9 on 1 7-seg display
        n_cars_in_diesel_queue,         // to represent max 9 on 1 7-seg display
        total_gasoline_needed,          // to represent max 99 on 2 7-seg displays
        total_diesel_needed,            // to represent max 99 on 2 7-seg displays
        invalid_gasoline_car,           // to lightup dot at an2
        invalid_diesel_car,             // to lightup dot at an0
        invalid_setup_params            // to lightup all dots
    );
    
    
    
 
    reg [18:0] sevenseg_refresh_counter;
    initial sevenseg_refresh_counter<= 0;
    always @(posedge mclk) sevenseg_refresh_counter = sevenseg_refresh_counter+1;
    
    wire [3:0] gasoline_ones;
    wire [3:0] gasoline_tens;
    wire [3:0] gasoline_hundreds;
    wire [3:0] diesel_ones;
    wire [3:0] diesel_tens;
    wire [3:0] diesel_hundreds;
    binary_to_BCD b2bcd1(total_gasoline_needed, gasoline_ones, gasoline_tens, gasoline_hundreds);
    binary_to_BCD b2bcd2(total_diesel_needed, diesel_ones, diesel_tens, diesel_hundreds);
    
    reg [3:0] tmp_digit;
    
    always @(sevenseg_refresh_counter[18:17])
    begin
        case (sevenseg_refresh_counter[18:17])
            2'b00:
                begin
                    an = 4'b1110;
                    // ligth if one 0
                    dp = !(invalid_diesel_car | invalid_setup_params);
                    if (! btn[1]) //if not in list mode
                        tmp_digit = n_cars_in_diesel_queue;
                    else if (total_diesel_needed != 8'b11111111)
                        tmp_digit = diesel_ones;
                    else
                        tmp_digit = 4'b1111;
                end
            2'b01:
                begin
                    an = 4'b1101;
                    // ligth if invalid_setup_params 1
                    dp = !invalid_setup_params;
                    if (! btn[1]) //if not in list mode
                        // this will turn of 7-seg but keep dp
                        tmp_digit = 4'b1111;
                    else if (total_diesel_needed != 8'b11111111)
                        tmp_digit = diesel_tens;
                    else
                        tmp_digit = 4'b1111;
                end
            2'b10:
                begin
                    an = 4'b1011;
                    // ligth if one 0
                    dp = !(invalid_gasoline_car | invalid_setup_params);
                    if (! btn[1]) //if not in list mode
                        tmp_digit = n_cars_in_gasoline_queue;
                    else if (total_gasoline_needed != 8'b11111111)
                        tmp_digit = gasoline_ones;
                    else
                        tmp_digit = 4'b1111;
                end
            2'b11:
                begin
                    an = 4'b0111;
                    // ligth if invalid_setup_params 1
                    dp = !invalid_setup_params;
                    if (! btn[1]) //if not in list mode
                        // this will turn of 7-seg but keep dp
                        tmp_digit = 4'b1111;
                    else if (total_gasoline_needed != 8'b11111111)
                        tmp_digit = gasoline_tens;
                    else
                        tmp_digit = 4'b1111;
                end
            default:
                begin
                    an = 4'b1111;
                    tmp_digit = 4'b1111;
                end
        endcase
        
        case (tmp_digit)
            4'd0: seg <= ~7'h3F;
            4'd1: seg <= ~7'h06;
            4'd2: seg <= ~7'h5B;
            4'd3: seg <= ~7'h4F;
            4'd4: seg <= ~7'h66;
            4'd5: seg <= ~7'h6D;
            4'd6: seg <= ~7'h7D;
            4'd7: seg <= ~7'h07;
            4'd8: seg <= ~7'h7F;
            4'd9: seg <= ~7'h6F;
            default: seg <= ~7'b0000000;
        endcase
    
    
        
    end
    
    // VGA
    assign OutBlue = 0;
    assign OutGreen = 0;
    assign OutRed = 0;
    assign HS = 0;
    assign VS = 0;

endmodule


module binary_to_BCD(A,ONES,TENS,HUNDREDS);
    input [7:0] A;
    output [3:0] ONES, TENS, HUNDREDS;
    wire [3:0] c1,c2,c3,c4,c5,c6,c7;
    wire [3:0] d1,d2,d3,d4,d5,d6,d7;
    assign d1 = {1'b0,A[7:5]};
    assign d2 = {c1[2:0],A[4]};
    assign d3 = {c2[2:0],A[3]};
    assign d4 = {c3[2:0],A[2]};
    assign d5 = {c4[2:0],A[1]};
    assign d6 = {1'b0,c1[3],c2[3],c3[3]};
    assign d7 = {c6[2:0],c4[3]};
    binary_to_BCD_add3 m1(d1,c1);
    binary_to_BCD_add3 m2(d2,c2);
    binary_to_BCD_add3 m3(d3,c3);
    binary_to_BCD_add3 m4(d4,c4);
    binary_to_BCD_add3 m5(d5,c5);
    binary_to_BCD_add3 m6(d6,c6);
    binary_to_BCD_add3 m7(d7,c7);
    assign ONES = {c5[2:0],A[0]};
    assign TENS = {c7[2:0],c5[3]};
    assign HUNDREDS = {0,0,c6[3],c7[3]};
endmodule

module binary_to_BCD_add3(in,out);
    input [3:0] in;
    output [3:0] out;
    reg [3:0] out;
    always @ (in)
        case (in)
            4'b0000: out <= 4'b0000;
            4'b0001: out <= 4'b0001;
            4'b0010: out <= 4'b0010;
            4'b0011: out <= 4'b0011;
            4'b0100: out <= 4'b0100;
            4'b0101: out <= 4'b1000;
            4'b0110: out <= 4'b1001;
            4'b0111: out <= 4'b1010;
            4'b1000: out <= 4'b1011;
            4'b1001: out <= 4'b1100;
            default: out <= 4'b0000;
        endcase
endmodule