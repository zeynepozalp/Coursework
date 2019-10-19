`timescale 1ns / 1ps
module MaskROM (input [3:0] RomAddress, output reg[7:0] RomDataOut);
/*  Please write your code below  */
	always@(RomAddress) begin
		if(RomAddress==0) begin
			RomDataOut<=8'b00000000;
		end
		else if(RomAddress==1) begin
			RomDataOut<=8'b00001111;
		end
		else if(RomAddress==2) begin
			RomDataOut<=8'b00011110;
		end
		else if(RomAddress==3) begin
			RomDataOut<=8'b00110000;
		end
		else if(RomAddress==4) begin
			RomDataOut<=8'b01010000;
		end
		else if(RomAddress==5) begin
			RomDataOut<=8'b01100110;
		end
		else if(RomAddress==6) begin
			RomDataOut<=8'b01100110;
		end
		else if(RomAddress==7) begin
			RomDataOut<=8'b01111110;
		end
		else if(RomAddress==8) begin
			RomDataOut<=8'b10000001;
		end
		else if(RomAddress==9) begin
			RomDataOut<=8'b10100000;
		end
		else if(RomAddress==10) begin
			RomDataOut<=8'b10100110;
		end
		else if(RomAddress==11) begin
			RomDataOut<=8'b10111101;
		end
		else if(RomAddress==12) begin
			RomDataOut<=8'b11000000;
		end
		else if(RomAddress==13) begin
			RomDataOut<=8'b11010000;
		end
		else if(RomAddress==14) begin
			RomDataOut<=8'b11010011;
		end
		else begin
			RomDataOut<=8'b11100110;
		end
	end

/*  Please write your code above  */
endmodule


/*mode 0:read, 1:write*/
module RgbRAM (input Mode,input [3:0] RamAddress, input [23:0] RamDataIn,
					input [7:0] Mask,input [2:0] Op, input CLK, output reg [23:0] RamDataOut);
/*  Please write your code below  */

	reg [23:0] memory[15:0];
	reg i;
	integer j;

	initial begin
		for(j=0;j<=15;j=j+1) begin
			memory[j]<=0;
		end
	end

	always@(RamAddress or negedge Mode) begin
		if(Mode==0) begin
			RamDataOut<=memory[RamAddress];
		end
	end

	always@(posedge CLK) begin
		if(Mode==1) begin
			if(Op==0) begin
				memory[RamAddress][7:0]=RamDataIn[7:0] & Mask;
				memory[RamAddress][15:8]=RamDataIn[15:8] & Mask;
				memory[RamAddress][23:16]=RamDataIn[23:16] & Mask;
			end
			else if(Op==1) begin
				memory[RamAddress][7:0]=RamDataIn[7:0] | Mask;
				memory[RamAddress][15:8]=RamDataIn[15:8] | Mask;
				memory[RamAddress][23:16]=RamDataIn[23:16] | Mask;
			end
			else if(Op==2) begin
				memory[RamAddress][7:0]=RamDataIn[7:0] ^ Mask;
				memory[RamAddress][15:8]=RamDataIn[15:8] ^ Mask;
				memory[RamAddress][23:16]=RamDataIn[23:16] ^ Mask;
			end
			else if(Op==3) begin
				memory[RamAddress][7:0]=((RamDataIn[7:0] + Mask > 255) ? 255 : RamDataIn[7:0] + Mask);
				memory[RamAddress][15:8]=((RamDataIn[15:8] + Mask > 255) ? 255 : RamDataIn[15:8] + Mask);
				memory[RamAddress][23:16]=((RamDataIn[23:16] + Mask > 255) ? 255 : RamDataIn[23:16] + Mask);
			end
			else if(Op==4) begin
				memory[RamAddress][7:0]=((RamDataIn[7:0] < Mask) ? 0 : RamDataIn[7:0] - Mask);
				memory[RamAddress][15:8]=((RamDataIn[15:8] < Mask) ? 0 : RamDataIn[15:8] - Mask);
				memory[RamAddress][23:16]=((RamDataIn[23:16] < Mask) ? 0 : RamDataIn[23:16] - Mask);
			end
			else if(Op==5) begin
				memory[RamAddress][7:0]=((RamDataIn[7:0] + 1 > 255) ? 255 : RamDataIn[7:0] + 1);
				memory[RamAddress][15:8]=((RamDataIn[15:8] + 1 > 255) ? 255 : RamDataIn[15:8] + 1);
				memory[RamAddress][23:16]=((RamDataIn[23:16] + 1 > 255) ? 255 : RamDataIn[23:16] + 1);
			end
			else if(Op==6) begin
				memory[RamAddress][7:0]=((RamDataIn[7:0] < 1) ? 0 : RamDataIn[7:0] - 1);
				memory[RamAddress][15:8]=((RamDataIn[15:8] < 1) ? 0 : RamDataIn[15:8] - 1);
				memory[RamAddress][23:16]=((RamDataIn[23:16] < 1) ? 0 : RamDataIn[23:16] - 1);
			end
			else begin
				i=memory[RamAddress][7];
				memory[RamAddress][7:0]= RamDataIn[7:0]<<1;
				memory[RamAddress][0]=i;
				i=memory[RamAddress][15];
				memory[RamAddress][15:8]= RamDataIn[15:8]<<1;
				memory[RamAddress][8]=i;
				i=memory[RamAddress][23];
				memory[RamAddress][23:16]= RamDataIn[23:16]<<1;
				memory[RamAddress][16]=i;
			end
			RamDataOut=memory[RamAddress];
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
