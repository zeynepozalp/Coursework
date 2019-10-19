`timescale 1ns / 1ps

module testbenchRAM(
    );

reg Mode;
reg [3:0] RamAddress;
reg [23:0] RamDataIn;
reg [7:0] Mask;
reg [2:0] Op;
reg CLK;
wire [23:0] RamDataOut;
reg [23:0] expectedOutput [0:11];

integer i;
integer k;
integer result;
integer wrongInitFlag;
integer wrongRamValueFlag;

RgbRAM INS (Mode, RamAddress, RamDataIn, Mask, Op, CLK, RamDataOut);

//Set initial values
initial CLK = 1;
always #5 CLK = ~CLK;

/*mode 0:read, 1:write*/	
initial begin
$display("Starting Testbench");

//12 test cases
expectedOutput[0]= 24'b100000001000001000000010;//AND test
expectedOutput[1]= 24'b101001111110011111100110;//OR test
expectedOutput[2]= 24'b001001110110010111100100;//XOR test
expectedOutput[3]= 24'b100100001101001001010001;//ADD test
expectedOutput[4]= 24'b111111111111111111111111;//ADD_OVERFLOW test
expectedOutput[5]= 24'b000000000000000000000000;//SUB_UNDERFLOW test
expectedOutput[6]= 24'b011100101011010000110011;//SUB test
expectedOutput[7]= 24'b100000101100010001000011;//INC test
expectedOutput[8]= 24'b111111111111111111111110;//INC_OVERFLOW test
expectedOutput[9]= 24'b100000001100001001000001;//DEC test
expectedOutput[10]=24'b000000000000000000000001;//DEC_UNDERFLOW test
expectedOutput[11]=24'b000000111000011110000100;//ROTL test  

i = 0;
k = 0; //expectedOutput index to compare the results
result = 0;
wrongInitFlag = 0;
wrongRamValueFlag = 0;

Mode=0; //read mode, CLK cycles do not affect.
#1

//check if all RAM cells are initially 0.
for(i = 0; i <= 15; i=i+1)
begin
	RamAddress = i;
	#1
	if(RamDataOut!=0)
	begin
		wrongInitFlag = 1;
	end
end //for end

if(wrongInitFlag==1)
begin
	$display("wrong initial cell values");
end
else
begin
	result = result + 1;
end

//test cases begin, each case writes onto a different (0->11) RAM cells.

RamDataIn = 24'b100000011100001101000010;
RamAddress = 0;
Mode=1'b1; //WR
Op=3'b000; //AND
Mask=8'b10100110;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after AND %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b001; //OR
RamAddress = 1;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after OR %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b010; //XOR
RamAddress = 2;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after XOR %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b011; //ADD
RamAddress = 3;
Mask=8'b00001111;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after ADD %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b011; //ADD_OVERFLOW
RamAddress = 4;
Mask=8'b11100110;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after ADD_OVERFLOW %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b100; //SUB_UNDERFLOW
RamAddress = 5;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after SUB_UNDERFLOW %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b100; //SUB
RamAddress = 6;
Mask=8'b00001111;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after SUB %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

Mode=1'b1; //WR
Op=3'b101; //INC
RamAddress = 7;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after INC %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

RamDataIn = 24'b111111111111111111111101; //RG overflow, B doesnt -------------
Mode=1'b1; //WR
Op=3'b101; //INC_OVERFLOW
RamAddress = 8;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after INC_OVERFLOW %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

RamDataIn = 24'b100000011100001101000010; //init value -------------
Mode=1'b1; //WR
Op=3'b110; //DEC
RamAddress = 9;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after DEC %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

RamDataIn = 24'b000000000000000000000010; //RG underflow, B doesnt -------------
Mode=1'b1; //WR
Op=3'b110; //DEC_UNDERFLOW
RamAddress = 10;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after DEC_UNDERFLOW %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end
k=k+1;

RamDataIn = 24'b100000011100001101000010; //init value -------------
Mode=1'b1; //WR
Op=3'b111; //ROTL
RamAddress = 11;
#5;
Mode=1'b0; //RD
#5;
$display("RamDataOut after ROTL %b",RamDataOut);
if(RamDataOut==expectedOutput[k])
begin
	result = result + 1;
end



//Check if the resulting data saved to RAM cells correctly:
$display("Starting to read 12 RAM cells:");
Mode=1'b0; //RD
for(i = 0; i < 12; i=i+1)
begin
RamAddress = i;
#1;
if(RamDataOut!=expectedOutput[i])
begin
	wrongRamValueFlag = 1;
end
$display("RamDataOut at cell %d: %b",i, RamDataOut);
end //for

if(wrongRamValueFlag == 0)
begin
	result = result + 3;
end

$display("Result %d",result); //max 16 (1 for init. RAM cells zero, 12 for cases, 3 for RAM cell read)
$finish;
end
 
endmodule

