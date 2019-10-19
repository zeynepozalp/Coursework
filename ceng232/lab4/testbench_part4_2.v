`timescale 1ns / 1ps

module testbench_part4_2(
);

  reg [2:0] n_gasoline_pumps; // for setup mode, max 6
  reg [2:0] n_diesel_pumps;   // for setup mode, max 6
  reg [3:0] fuel_amount;      // for add car mode, max 8
  reg fuel_type;				    // for add car mode, gas(0) or diesel(1)
  reg [1:0] mode;
  reg CLK; 
  wire [5:0] pump_status; 				 // pump is working or not, max 6 pumps
  wire is_gasoline_queue_not_full;		 // gasoline queue full warning
  wire is_diesel_queue_not_full;  		 // diesel queue full warning
  wire [3:0] n_cars_in_gasoline_queue; // to represent max 9 on 1 7-seg display
  wire [3:0] n_cars_in_diesel_queue;   // to represent max 9 on 1 7-seg display
  wire [7:0] total_gasoline_needed;    // to represent max 99 on 2 7-seg displays
  wire [7:0] total_diesel_needed;      // to represent max 99 on 2 7-seg displays

  lab4_2 ins(
    mode,
    n_gasoline_pumps, 
    n_diesel_pumps,
    fuel_amount,
    fuel_type,
    CLK, 
    pump_status, 
    is_gasoline_queue_not_full,
    is_diesel_queue_not_full,
    n_cars_in_gasoline_queue, 
    n_cars_in_diesel_queue,
    total_gasoline_needed, 
    total_diesel_needed,
    invalid_gasoline_car,
    invalid_diesel_car,
    invalid_setup_params
  );
  
  integer result;

  initial CLK = 1;

  always #5 CLK = ~CLK;

  initial
    begin
		result = 0;

      #1;
		//dont care the initial status of anything.

      //setup mode
      mode=2'b10;
      n_gasoline_pumps=3'b011; //3
      n_diesel_pumps=3'b010; //2
      //total 5 pumps (3 gasoline, 2 diesel) will be active

      #10;
		
      if( pump_status == 6'b111110
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 1");
      
      //add car and run simulation
      mode=2'b01;

      //try adding gasoline car with fuel_amount=0 (invalid)
      fuel_amount=4'b0000;
      fuel_type=1'b0;

      #10;
		
      if( pump_status == 6'b111110
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 1
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 2");

      //first gasoline car fuel_amount=3
      fuel_amount=4'b0011;

      #10;
		
      if( pump_status == 6'b011110
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 3
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 3");
		 
      //first diesel car fuel_amount=4
      fuel_amount=4'b0100;
      fuel_type=1'b1;

      #10;
		
      if( pump_status == 6'b011010
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 2
       && total_diesel_needed == 4
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 4");
		 
      //second diesel car fuel_amount=8
      fuel_amount=4'b1000;

      #10;
	
      if( pump_status == 6'b011000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 1
       && total_diesel_needed == 11
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 5");
		 
      //second gasoline car fuel_amount=5
      fuel_amount=4'b0101;
      fuel_type=1'b0;

      #10;
	
      if( pump_status == 6'b101000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 5
       && total_diesel_needed == 9
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 6");
		 
      //third gasoline car fuel_amount=7
      fuel_amount=4'b0111;

      #10;
	
      if( pump_status == 6'b001000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 11
       && total_diesel_needed == 7
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 7");
		 
      //third diesel car fuel_amount=1
      fuel_amount=4'b0001;
      fuel_type=1'b1;

      #10;
	
      if( pump_status == 6'b001100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 9
       && total_diesel_needed == 6
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 8");
		 
      //start adding more diesel cars
      fuel_amount=4'b1000;

      #10;

      if( pump_status == 6'b001000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 7
       && total_diesel_needed == 13
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 9");
		 
      fuel_amount=4'b1000;

      #10;

      if( pump_status == 6'b001100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 5
       && total_diesel_needed == 19
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 10");
		 
      fuel_amount=4'b0111;

      #10;

      if( pump_status == 6'b011000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 3
       && total_diesel_needed == 25
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 11");
		 
      fuel_amount=4'b0110;

      #10;

      if( pump_status == 6'b011000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 2
       && total_diesel_needed == 29
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 12");
		 
      fuel_amount=4'b0101;

      #10;

      if( pump_status == 6'b011010
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 4
       && total_gasoline_needed == 1
       && total_diesel_needed == 32
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 13");
		 
      fuel_amount=4'b0100;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 4
       && total_gasoline_needed == 0
       && total_diesel_needed == 35
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 14");
		 
      fuel_amount=4'b0011;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 5
       && total_gasoline_needed == 0
       && total_diesel_needed == 36
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 15");
		 
      fuel_amount=4'b1000;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 6
       && total_gasoline_needed == 0
       && total_diesel_needed == 42
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 16");
		 
      fuel_amount=4'b0110;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 7
       && total_gasoline_needed == 0
       && total_diesel_needed == 46
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 17");
		 
      fuel_amount=4'b0101;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 8
       && total_gasoline_needed == 0
       && total_diesel_needed == 49
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 18");
		 
      fuel_amount=4'b0100;

      #10;

      if( pump_status == 6'b111100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 8
       && total_gasoline_needed == 0
       && total_diesel_needed == 47
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 1
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 19");
		 
      fuel_amount=4'b0011;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 8
       && total_gasoline_needed == 0
       && total_diesel_needed == 49
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 20");
		 
      //start adding more gasoline cars
      fuel_amount=4'b1000;
      fuel_type=1'b0;

      #10;

      if( pump_status == 6'b011000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 8
       && total_gasoline_needed == 8
       && total_diesel_needed == 47
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 21");
		 
      fuel_amount=4'b1000;

      #10;

      if( pump_status == 6'b001010
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 8
       && total_gasoline_needed == 15
       && total_diesel_needed == 45
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 22");
		 
      fuel_amount=4'b0111;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 7
       && total_gasoline_needed == 20
       && total_diesel_needed == 44
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 23");
		 
      fuel_amount=4'b0110;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 1
       && n_cars_in_diesel_queue == 7
       && total_gasoline_needed == 23
       && total_diesel_needed == 42
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 24");
		 
      fuel_amount=4'b0101;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 7
       && total_gasoline_needed == 25
       && total_diesel_needed == 40
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 25");
		 
      fuel_amount=4'b0100;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 3
       && n_cars_in_diesel_queue == 7
       && total_gasoline_needed == 26
       && total_diesel_needed == 38
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 26");
		 
      fuel_amount=4'b0011;

      #10;

      if( pump_status == 6'b000100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 4
       && n_cars_in_diesel_queue == 7
       && total_gasoline_needed == 26
       && total_diesel_needed == 36
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 27");
		 
      fuel_amount=4'b0010;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 5
       && n_cars_in_diesel_queue == 6
       && total_gasoline_needed == 25
       && total_diesel_needed == 35
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 28");
		 
      //dont add car, simulation only
      mode=2'b00;

      #10; //simulate 5 ticks

      if( pump_status == 6'b100010
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 5
       && n_cars_in_diesel_queue == 6
       && total_gasoline_needed == 22
       && total_diesel_needed == 33
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 29");
		 
		#10;
		
      if( pump_status == 6'b011000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 4
       && n_cars_in_diesel_queue == 5
       && total_gasoline_needed == 20
       && total_diesel_needed == 32
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 30");
		 
		#10;
				
      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 5
       && total_gasoline_needed == 19
       && total_diesel_needed == 30
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 31");
		 
		#10;
		
      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 5
       && total_gasoline_needed == 16
       && total_diesel_needed == 28
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 32");
		 
		#10;
				
      if( pump_status == 6'b000100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 5
       && total_gasoline_needed == 13
       && total_diesel_needed == 26
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 33");
		 
      //invalid setup mode params
      mode=2'b10;
      n_gasoline_pumps=3'b110; //6
      n_diesel_pumps=3'b110; //6
      //total 12 pumps (6 gasoline, 6 diesel), but invalid.

      #10; 
				
      if( pump_status == 6'b000100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 5
       && total_gasoline_needed == 13
       && total_diesel_needed == 26
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 1) result = result + 1;
		 else $display("error case 34");
		 
      mode=2'b00;

      #10; //simulate until the current simulation is completed
						
      if( pump_status == 6'b000010
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 4
       && total_gasoline_needed == 10
       && total_diesel_needed == 25
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 35");

		#10;
								
      if( pump_status == 6'b001000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 2
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 7
       && total_diesel_needed == 24
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 36");
		 
		#10;
										
      if( pump_status == 6'b110000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 1
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 5
       && total_diesel_needed == 22
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 37");
		 
		#10;
												
      if( pump_status == 6'b010100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 4
       && total_diesel_needed == 20
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 38");
		 
		#10;
														
      if( pump_status == 6'b010000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 2
       && total_diesel_needed == 19
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 39");
		 
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 0
       && total_diesel_needed == 17
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 40");
		 
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 0
       && total_diesel_needed == 15
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 41");
		 
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 0
       && total_diesel_needed == 13
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 42");
		 
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 0
       && total_diesel_needed == 11
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 43");
		
		#10;
														
      if( pump_status == 6'b111010
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 0
       && total_diesel_needed == 9
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 44");
		
		#10;
														
      if( pump_status == 6'b111100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 0
       && total_diesel_needed == 8
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 45");
		
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 7
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 46");
		
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 5
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 47");
		
		#10;
														
      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 3
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 48");
		
		#10;
														
      if( pump_status == 6'b111100
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 1
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 49");
		
		#10;
														
      if( pump_status == 6'b111110
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) result = result + 1;
		 else $display("error case 50");
		 
		$display("Result %d",result);//50 cases in total.

      $finish;

    end

endmodule
