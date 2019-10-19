`timescale 1ns / 1ps
module MaskROM (input [3:0] RomAddress, output reg[7:0] RomDataOut);
/*  Please write your code below  */
always@(RomAddress)
 begin
	if(RomAddress==0)
		RomDataOut<=8'b00000000;
	else if(RomAddress==1)
		RomDataOut<=8'b00001111;
	else if(RomAddress==2)
		RomDataOut<=8'b00011110;
	else if(RomAddress==3)
		RomDataOut<=8'b00110000;
	else if(RomAddress==4)
		RomDataOut<=8'b01010000;
	else if(RomAddress==5)
		RomDataOut<=8'b01100110;
	else if(RomAddress==6)
		RomDataOut<=8'b01101010;
	else if(RomAddress==7)
		RomDataOut<=8'b01111110;
	else if(RomAddress==8)
		RomDataOut<=8'b10000001;
	else if(RomAddress==9)
		RomDataOut<=8'b10100000;
	else if(RomAddress==10)
		RomDataOut<=8'b10100110;
	else if(RomAddress==11)
		RomDataOut<=8'b10111101;
	else if(RomAddress==12)
		RomDataOut<=8'b11000000;
	else if(RomAddress==13)
		RomDataOut<=8'b11010000;
	else if(RomAddress==14)
		RomDataOut<=8'b11010011;
	else if(RomAddress==15)
		RomDataOut<=8'b11100110;
 end

/*  Please write your code above  */
endmodule


/*mode 0:read, 1:write*/																							
module RgbRAM (input Mode,input [3:0] RamAddress, input [23:0] RamDataIn,
					input [7:0] Mask,input [2:0] Op, input CLK, output reg [23:0] RamDataOut);
/*  Please write your code below  */
reg [23:0]memory[0:15];
initial
 begin
 memory[0]=0;
 memory[1]=0;
 memory[2]=0;
 memory[3]=0;
 memory[4]=0;
 memory[5]=0;
 memory[6]=0;
 memory[7]=0;
 memory[8]=0;
 memory[9]=0;
memory[10]=0;
memory[11]=0;
memory[12]=0;
memory[13]=0;
memory[14]=0; 
memory[15]=0; 
 end
	always@(RamAddress or Mode)
	begin
	if(Mode==0)
		begin
		RamDataOut<=memory[RamAddress];
		end

	end

always@(posedge CLK)
begin
if(Mode==1)
begin
	if(Op==0)
		begin 
			memory[RamAddress][23:16]=RamDataIn[23:16] & Mask;
			memory[RamAddress][15:8]=RamDataIn[15:8] & Mask;
			memory[RamAddress][7:0]=RamDataIn[7:0] & Mask;
		end
	else if(Op==1)
	begin 
			memory[RamAddress][23:16]=RamDataIn[23:16] | Mask;
			memory[RamAddress][15:8]=RamDataIn[15:8] | Mask;
			memory[RamAddress][7:0]=RamDataIn[7:0] | Mask;
	end
	else if(Op==2)
	begin 
			memory[RamAddress][23:16]=RamDataIn[23:16] ^ Mask;
			memory[RamAddress][15:8]=RamDataIn[15:8] ^ Mask;
			memory[RamAddress][7:0]=RamDataIn[7:0] ^ Mask;
	end
	else if(Op==3)
	begin 
		if(RamDataIn[23:16] +Mask<=255)
			begin 
			memory[RamAddress][23:16]=RamDataIn[23:16] +Mask;
			end
		else
			begin 
			memory[RamAddress][23:16]=8'b11111111;
			end
		if(RamDataIn[15:8] +Mask<=255)
			begin 
			memory[RamAddress][15:8]=RamDataIn[15:8] +Mask;
			end
			else
			begin 
			memory[RamAddress][15:8]=8'b11111111;
			end
		if(RamDataIn[7:0] +Mask<=255)
			begin 
			memory[RamAddress][7:0]=RamDataIn[7:0] +Mask;
			end
		else
			begin 
			memory[RamAddress][7:0]=8'b11111111;
			end
	
	
	end
	else if(Op==4)
	begin 
			if(RamDataIn[23:16] >=Mask)
			begin 
			memory[RamAddress][23:16]=(RamDataIn[23:16] -Mask);
			end
			else if(RamDataIn[23:16] < Mask)
			begin 
			memory[RamAddress][23:16]=8'b00000000;
			end
			/*15:8 bit*/
			if(RamDataIn[15:8] >= Mask)
			begin 
			memory[RamAddress][15:8]=(RamDataIn[15:8] -Mask);
			end
			else  if(RamDataIn[23:16] < Mask)
			begin 
			memory[RamAddress][15:8]=8'b00000000;
			end
			/*0 :7 bit*/
			if(RamDataIn[7:0] >=Mask)
			begin 
			memory[RamAddress][7:0]=(RamDataIn[7:0] -Mask);
			end
			else  if(RamDataIn[23:16] < Mask)
			begin 
			memory[RamAddress][7:0]=8'b00000000;
			end
			
			
			
	end
	else if(Op==5)
	begin 
	/* 111111 ise ne yapıcanı yazmadın*/
	if(RamDataIn[23:16]==8'b11111111)
		begin
			memory[RamAddress][23:16]=RamDataIn[23:16];
		end
	else
		begin
		memory[RamAddress][23:16]=RamDataIn[23:16]+8'b00000001;
		end
	if(RamDataIn[15:8]==8'b11111111)
		begin
			memory[RamAddress][15:8]=RamDataIn[15:8];
		end
	else
		begin
		memory[RamAddress][15:8]=RamDataIn[15:8]+8'b00000001;
		end
	if(RamDataIn[7:0]==8'b11111111)
		begin
			memory[RamAddress][7:0]=RamDataIn[7:0];
		end
	else
		begin
		memory[RamAddress][7:0]=RamDataIn[7:0]+8'b00000001;
		end
	end
	else if(Op==6)
	begin 
	if(RamDataIn[23:16]==8'b00000000)
		begin
		memory[RamAddress][23:16]=0;
		end
	else
		begin
		memory[RamAddress][23:16]=(RamDataIn[23:16]-8'b00000001);
		end
	if(RamDataIn[15:8]==0)
		begin
		memory[RamAddress][15:8]=0;
		end
	else
		begin
		memory[RamAddress][15:8]=RamDataIn[15:8]-8'b00000001;
		end
	if(RamDataIn[7:0]==0)
		begin
		memory[RamAddress][7:0]=0;
		end
	else
		begin
		memory[RamAddress][7:0]=RamDataIn[7:0]-8'b00000001;
		end
	end
	
	else if(Op==7)
	begin 
			memory[RamAddress][23:17]=RamDataIn[22:16];
			memory[RamAddress][16]=RamDataIn[23];
			memory[RamAddress][15:9]=RamDataIn[14:8];
			memory[RamAddress][8]=RamDataIn[15];
			memory[RamAddress][7:1]=RamDataIn[6:0] ;
			memory[RamAddress][0]=RamDataIn[7];
	end
	

end

end

/*  Please write your code above  */
endmodule


module RgbMaskModule(input Mode, input [3:0] Address, input [23:0] RGBin,input [2:0] Op,  input CLK, output wire [23:0] RGBout);
	
	/*  DO NOT edit this module  */
	
	wire [7:0]  romResult;

	MaskROM RO(Address, romResult);
	RgbRAM RA(Mode, Address, RGBin,romResult, Op, CLK, RGBout);
endmodule
