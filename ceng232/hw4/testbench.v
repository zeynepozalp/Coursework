`timescale 1ns / 1ps

module testbench(
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

  initial CLK = 1;

  always #5 CLK = ~CLK;

  initial
    begin

      #1;     
      // set monitor to inputs and outputs
      $display("\nTIME\tPUMPS\t?GAS\t?DSL\tN-GAS\tN-DSL\tF-GAS\tF-DSL\tINV-GAS\tINV-DSL\tINV-STP\n");

      $monitor("T: %3d\t%b\t%b\t%b\t%d\t%d\t%d\t%d\t%b\t%b\t%b\n",
               $time, pump_status, is_gasoline_queue_not_full, is_diesel_queue_not_full,
               n_cars_in_gasoline_queue, n_cars_in_diesel_queue,
               total_gasoline_needed, total_diesel_needed,
               invalid_gasoline_car, invalid_diesel_car, invalid_setup_params);

      //setup mode

      mode=2'b10;
      n_gasoline_pumps=3'b011; //3
      n_diesel_pumps=3'b010; //2
      //total 5 pumps (3 gasoline, 2 diesel) will be active

      #10;

      //add car and run simulation
      mode=2'b01;

      //try adding gasoline car with fuel_amount=0 (invalid)
      fuel_amount=4'b0000;
      fuel_type=1'b0;

      #10;

      //first gasoline car fuel_amount=3
      fuel_amount=4'b0011;

      #10;

      //first diesel car fuel_amount=4
      fuel_amount=4'b0100;
      fuel_type=1'b1;

      #10;

      //second diesel car fuel_amount=8
      fuel_amount=4'b1000;

      #10;

      //second gasoline car fuel_amount=5
      fuel_amount=4'b0101;
      fuel_type=1'b0;

      #10;

      //third gasoline car fuel_amount=7
      fuel_amount=4'b0111;

      #10;

      //third diesel car fuel_amount=1
      fuel_amount=4'b0001;
      fuel_type=1'b1;

      #10;

      //start adding more diesel cars
      fuel_amount=4'b1000;

      #10;

      fuel_amount=4'b1000;

      #10;

      fuel_amount=4'b0111;

      #10;

      fuel_amount=4'b0110;

      #10;

      fuel_amount=4'b0101;

      #10;

      fuel_amount=4'b0100;

      #10;

      fuel_amount=4'b0011;

      #10;

      fuel_amount=4'b1000;

      #10;

      fuel_amount=4'b0111;

      #10;

      fuel_amount=4'b0110;

      #10;

      fuel_amount=4'b0101;

      #10;

      fuel_amount=4'b0100;

      #10;

      //start adding more gasoline cars with fuel_amount=8
      fuel_amount=4'b1000;
      fuel_type=1'b0;

      #10;

      fuel_amount=4'b1000;

      #10;

      fuel_amount=4'b0111;

      #10;

      fuel_amount=4'b0110;

      #10;

      fuel_amount=4'b0101;

      #10;

      fuel_amount=4'b0100;

      #10;

      fuel_amount=4'b0011;

      #10;

      fuel_amount=4'b0010;

      #10;

      //dont add car, simulation only
      mode=2'b00;

      #50; //simulate 5 ticks

      //invalid setup mode params
      mode=2'b10;
      n_gasoline_pumps=3'b110; //6
      n_diesel_pumps=3'b110; //6
      //total 12 pumps (6 gasoline, 6 diesel), but invalid.

      #10; 

      mode=2'b00;

      #500; //simulate until the current simulation is completed

      $finish;

    end

endmodule
