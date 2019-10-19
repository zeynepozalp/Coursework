`timescale 1ns / 1ps

module testbenchROM(
    );

reg [3:0] RomAddress;
wire [7:0] RomDataOut;
reg [7:0] testROM [0:15];
integer result;
integer i;

//module MaskROM (input [3:0] RomAddress, output reg[7:0] RomDataOut); //16 adress, 8 bit

MaskROM INS (RomAddress, RomDataOut);
  
initial  begin
testROM[0]= 8'b00000000;
testROM[1]= 8'b00001111;
testROM[2]= 8'b00011110;
testROM[3]= 8'b00110000;
testROM[4]= 8'b01010000;
testROM[5]= 8'b01100110;
testROM[6]= 8'b01101010;
testROM[7]= 8'b01111110;
testROM[8]= 8'b10000001;
testROM[9]= 8'b10100000;
testROM[10]=8'b10100110;
testROM[11]=8'b10111101;
testROM[12]=8'b11000000;
testROM[13]=8'b11010000;
testROM[14]=8'b11010011;
testROM[15]=8'b11100110;
end
  
  
initial begin
$display("Starting Testbench");
 
result = 0;
 
for(i = 0; i <= 15; i=i+1)
begin

#1;

RomAddress = i;

#1;

if(RomDataOut==testROM[i])
begin
	result=result+1;
end
else
begin
$display("Wrong result at index %d, value is %b", i, RomDataOut);
end


end

$display("Result %d",result);
$finish;
end
 
endmodule

