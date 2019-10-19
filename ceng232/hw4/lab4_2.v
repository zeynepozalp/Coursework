`timescale 1ns / 1ps

module lab4_2(
  input [1:0] mode,
  input [2:0] n_gasoline_pumps,      // for setup mode, max 6
  input [2:0] n_diesel_pumps,        // for setup mode, max 6
  input [3:0] fuel_amount,           // for add car mode, max 8
  input fuel_type,                   // for add car mode, gas(0) or diesel(1)
  input CLK,

  output reg [0:5] pump_status,                // pump is working or not, max 6 pumps
  output reg is_gasoline_queue_not_full,       // gasoline queue full warning
  output reg is_diesel_queue_not_full,         // diesel queue full warning

  output reg [3:0] n_cars_in_gasoline_queue,   // to represent max 9 on 1 7-seg display
  output reg [3:0] n_cars_in_diesel_queue,     // to represent max 9 on 1 7-seg display

  output reg [7:0] total_gasoline_needed,      // to represent max 99 on 2 7-seg displays
  output reg [7:0] total_diesel_needed,        // to represent max 99 on 2 7-seg displays

  // reset these after one clock
  output reg invalid_gasoline_car,             // to lightup dot at an2
  output reg invalid_diesel_car,               // to lightup dot at an0
  output reg invalid_setup_params              // to lightup all dots
);

// write your code here

	reg isSetup;
	reg [2:0] i;
	reg [0:3] gasoline_queue [0:7];
	reg [0:3] diesel_queue [0:7];
	reg [0:3] pumps [0:5];
	reg [2:0] gasoline;
  reg [2:0] diesel;

	initial begin
		is_gasoline_queue_not_full=0;
		is_diesel_queue_not_full=0;
		isSetup=0;
		pump_status=6'b000000;
		invalid_gasoline_car=0;
		invalid_diesel_car=0;
		invalid_setup_params=0;
		total_gasoline_needed=8'b11111111;
		total_diesel_needed=8'b11111111;
		n_cars_in_gasoline_queue=4'b1111;
		n_cars_in_diesel_queue=4'b1111;
		i=3'b000;
		gasoline=0;
		diesel=0;
		pumps[0]=0;
		pumps[1]=0;
		pumps[2]=0;
		pumps[3]=0;
		pumps[4]=0;
		pumps[5]=0;
		gasoline_queue[0]=0;
		gasoline_queue[1]=0;
		gasoline_queue[2]=0;
		gasoline_queue[3]=0;
		gasoline_queue[4]=0;
		gasoline_queue[5]=0;
		gasoline_queue[6]=0;
		gasoline_queue[7]=0;
		diesel_queue[0]=0;
		diesel_queue[1]=0;
		diesel_queue[2]=0;
		diesel_queue[3]=0;
		diesel_queue[4]=0;
		diesel_queue[5]=0;
		diesel_queue[6]=0;
		diesel_queue[7]=0;
	end

	always@(posedge CLK) begin
		if(mode==2'b10 || mode==2'b11) begin
			if(n_gasoline_pumps+n_diesel_pumps>6 || n_gasoline_pumps+n_diesel_pumps==0) begin
				invalid_setup_params=1;
			end
			else begin
				total_gasoline_needed=0;
				total_diesel_needed=0;
				n_cars_in_gasoline_queue=0;
				n_cars_in_diesel_queue=0;
				gasoline=n_gasoline_pumps;
				diesel=n_diesel_pumps;
				is_gasoline_queue_not_full=1;
				is_diesel_queue_not_full=1;

				for(i=0;i<6;i=i+1) begin
					if(i<gasoline+diesel) begin
						pump_status[i]=1;
					end
				end
				i=0;
				if(n_gasoline_pumps==0) begin
					total_gasoline_needed=8'b11111111;
					n_cars_in_gasoline_queue=4'b1111;
				end
				else if(n_diesel_pumps==0) begin
					n_cars_in_diesel_queue=4'b1111;
					total_diesel_needed=8'b11111111;
				end
				isSetup=1;
			end
		end
		else begin //simulation
			invalid_gasoline_car=0;
			invalid_diesel_car=0;
			invalid_setup_params=0;
			is_gasoline_queue_not_full=1;
			is_diesel_queue_not_full=1;
			if(isSetup==1) begin
					for(i=0;i<6;i=i+1) begin //visit pumps
						if(i<(gasoline+diesel)) begin
							if(pump_status[i]==1) begin //available pump
								if(i<gasoline) begin //Gasoline
									if(n_cars_in_gasoline_queue>0) begin //queue is not empty
										pump_status[i]=0; //make pump not available
										pumps[i]=gasoline_queue[0]; //put car in pumps
										n_cars_in_gasoline_queue=n_cars_in_gasoline_queue-1; //decrement queue number
										gasoline_queue[0]=gasoline_queue[1];
										gasoline_queue[1]=gasoline_queue[2];
										gasoline_queue[2]=gasoline_queue[3];
										gasoline_queue[3]=gasoline_queue[4];
										gasoline_queue[4]=gasoline_queue[5];
										gasoline_queue[5]=gasoline_queue[6];
										gasoline_queue[6]=gasoline_queue[7];
										gasoline_queue[7]=4'b0000;
										is_gasoline_queue_not_full=1;
									end
								end
								else begin //Diesel
									if(n_cars_in_diesel_queue>0) begin //queue is not empty
										pump_status[i]=0; //make pump not available
										pumps[i]=diesel_queue[0]; //put car in pumps
										n_cars_in_diesel_queue=n_cars_in_diesel_queue-1; //decrement queue number
										diesel_queue[0]=diesel_queue[1];
										diesel_queue[1]=diesel_queue[2];
										diesel_queue[2]=diesel_queue[3];
										diesel_queue[3]=diesel_queue[4];
										diesel_queue[4]=diesel_queue[5];
										diesel_queue[5]=diesel_queue[6];
										diesel_queue[6]=diesel_queue[7];
										diesel_queue[7]=4'b0000;
										is_diesel_queue_not_full=1;
									end
								end
							end
							else if(pump_status[i]==0) begin //not available pump
								if(i<gasoline) begin //gasoline
									total_gasoline_needed=total_gasoline_needed-1; //decrement total gasoline needed
									pumps[i]=pumps[i]-1; //decrement left fuel amount of that car
								end
								else begin //diesel
									total_diesel_needed=total_diesel_needed-1; //decrement total diesel needed
									pumps[i]=pumps[i]-1; //decrement left fuel amount of that car
								end
							end
						end
					end //for sonu
					i=0;

				if(mode==2'b01) begin //mode=01 car entrance
					if(fuel_type==0) begin //Gasoline
						if(fuel_amount>8 || fuel_amount<1 || n_cars_in_gasoline_queue==8 || n_gasoline_pumps==0) begin
							invalid_gasoline_car=1;
						end
						else begin
							if(n_cars_in_gasoline_queue!=0 || pump_status[gasoline-1]==0) begin //add to queue
								gasoline_queue[n_cars_in_gasoline_queue]=fuel_amount; //add to queue
								n_cars_in_gasoline_queue=n_cars_in_gasoline_queue+1; //increment queue number
								total_gasoline_needed=total_gasoline_needed+fuel_amount; //incerement total gasoline by fuel amount
							end
							else begin //go to pumps directly
								for(i=0;i<6;i=i+1) begin //visit pumps
									if(i<gasoline+diesel) begin
										if(pump_status[i]==1) begin //available pump
											pump_status[i]=0; //make pump not available
											pumps[i]=fuel_amount; //put car in pumps
											total_gasoline_needed=total_gasoline_needed+fuel_amount;
											i=6;
										end
									end
								end
								i=0;
							end
						end
					end // Gasoline sonu
					else begin //Diesel
						if(fuel_amount>8 || fuel_amount<1 || n_cars_in_diesel_queue==8 || n_diesel_pumps==0) begin
							invalid_diesel_car=1;
						end
						else begin
							if(n_cars_in_diesel_queue!=0 || pump_status[diesel+gasoline-1]==0) begin //add to queue
								diesel_queue[n_cars_in_diesel_queue]=fuel_amount; //add to queue
								n_cars_in_diesel_queue=n_cars_in_diesel_queue+1; //increment queue number
								total_diesel_needed=total_diesel_needed+fuel_amount; //incerement total gasoline by fuel amount
							end
							else begin //visit pumps
								for(i=0;i<6;i=i+1) begin //visit pumps
									if(i>=gasoline && i<gasoline+diesel) begin
										if(pump_status[i]==1) begin //available pump
											pump_status[i]=0; //make pump not available
											pumps[i]=fuel_amount; //put car in pumps
											total_diesel_needed=total_diesel_needed+fuel_amount;
											i=6;
										end
									end
								end
								i=0;
							end
						end // else sonu
					end //Diesel sonu
				end //Car entrance sonu

				if(n_cars_in_gasoline_queue==8) is_gasoline_queue_not_full=0;
				if(n_cars_in_diesel_queue==8) is_diesel_queue_not_full=0;

				for(i=0;i<6;i=i+1) begin
					if(i<gasoline+diesel && pumps[i]==0) begin //leave car from this pump
						pump_status[i]=1; //make pump available
					end
				end //leave car for sonu
				i=0;
		end //simulation sonu
	end end
	
endmodule
