`timescale 1ns / 1ps

module testbench(
);

  reg [2:0] n_gasoline_pumps;            // for setup mode, max 6
  reg [2:0] n_diesel_pumps;              // for setup mode, max 6
  reg [3:0] fuel_amount;                 // for add car mode, max 8
  reg fuel_type;				         // for add car mode, gas(0) or diesel(1)
  reg [1:0] mode;
  reg CLK; 
  wire [5:0] pump_status; 				 // pump is working or not, max 6 pumps
  wire is_gasoline_queue_not_full;		 // gasoline queue full warning
  wire is_diesel_queue_not_full;  		 // diesel queue full warning
  wire [3:0] n_cars_in_gasoline_queue;   // to represent max 9 on 1 7-seg display
  wire [3:0] n_cars_in_diesel_queue;     // to represent max 9 on 1 7-seg display
  wire [7:0] total_gasoline_needed;      // to represent max 99 on 2 7-seg displays
  wire [7:0] total_diesel_needed;        // to represent max 99 on 2 7-seg displays

  reg [15:0] passCounter;

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
  
  initial passCounter = 0;

  always #5 CLK = ~CLK;

  initial
    begin

      #1;     
                                         // MONITOR OUTPUT
      $display("\nTIME\tPUMPS\t?GAS\t?DSL\tN-GAS\tN-DSL\tF-GAS\tF-DSL\tINV-GAS\tINV-DSL\tINV-STP\n");

      $monitor("T: %3d\t%b\t%b\t%b\t%d\t%d\t%d\t%d\t%b\t%b\t%b\n",
               $time, pump_status, is_gasoline_queue_not_full, is_diesel_queue_not_full,
               n_cars_in_gasoline_queue, n_cars_in_diesel_queue,
               total_gasoline_needed, total_diesel_needed,
               invalid_gasoline_car, invalid_diesel_car, invalid_setup_params);


      mode = 2'b10;                      // SETUP MODE
      n_gasoline_pumps = 4;
      n_diesel_pumps   = 3;


      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 255
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 1) begin $display("timeUnit1: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit1: FAILED");
      

      n_gasoline_pumps = 0;
      n_diesel_pumps = 1;

      #10;

      if( pump_status == 6'b100000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 255
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit2: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit2: FAILED");
      
      mode = 2'b01;                      // CAR ENTRANCE MODE
      fuel_type = 1;
      fuel_amount = 6;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 255
       && total_diesel_needed == 6
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit3: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit3: FAILED");


      fuel_type = 0;
      fuel_amount = 3;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 255
       && total_diesel_needed == 5
       && invalid_gasoline_car == 1
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit4: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit4: FAILED");

      
      fuel_type = 1;
      fuel_amount = 1;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 255
       && total_diesel_needed == 5
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit5: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit5: FAILED");

      
      fuel_type = 1;
      fuel_amount = 3;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 255
       && total_diesel_needed == 7
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit6: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit6: FAILED");


      mode = 0;                          // SIMULATION MODE

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 255
       && total_diesel_needed == 6
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit7: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit7: FAILED");

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 255
       && total_diesel_needed == 5
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit8: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit8: FAILED");


      #10;

      if( pump_status == 6'b100000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 255
       && total_diesel_needed == 4
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit9: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit9: FAILED");

      
      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 255
       && total_diesel_needed == 4
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit10: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit10: FAILED");


      #10;

      if( pump_status == 6'b100000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 255
       && total_diesel_needed == 3
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit11: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit11: FAILED");


      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 255
       && total_diesel_needed == 3
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit12: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit12: FAILED");


      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 255
       && total_diesel_needed == 2
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit13: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit13: FAILED");


      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 15
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 255
       && total_diesel_needed == 1
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit14: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit14: FAILED");


      
      mode = 2'b10;                      // SETUP MODE
      n_gasoline_pumps = 2;
      n_diesel_pumps   = 1;

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit15: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit15: FAILED");

      mode = 2'b00;                      // SIMULATION MODE

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit16: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit16: FAILED");

      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit17: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit17: FAILED");

      mode = 2'b01;                      // CAR ENTRANCE MODE
      fuel_amount = 9;
      fuel_type = 1;
      
      #10;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 1
       && invalid_setup_params == 0) begin $display("timeUnit18: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit18: FAILED");
      
      fuel_amount = 8;

      #10;

      if( pump_status == 6'b110000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 8
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit19: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit19: FAILED");

      fuel_type = 0;
      fuel_amount = 7;

      #10;

      if( pump_status == 6'b010000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 7
       && total_diesel_needed == 7
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit20: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit20: FAILED");

      fuel_type = 1;
      fuel_amount = 8;

      #10;

      if( pump_status == 6'b010000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 1
       && total_gasoline_needed == 6
       && total_diesel_needed == 14
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit21: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit21: FAILED");

      fuel_amount = 1;

      #10;

      if( pump_status == 6'b010000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 5
       && total_diesel_needed == 14
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit22: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit22: FAILED");

      #10;

      if( pump_status == 6'b010000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 4
       && total_diesel_needed == 14
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit23: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit23: FAILED");

      fuel_amount = 8;
      fuel_type = 0;

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 11
       && total_diesel_needed == 13
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit24: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit24: FAILED");


      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 1
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 17
       && total_diesel_needed == 12
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit25: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit25: FAILED");

      mode = 2'b00;                      // SIMULATION MODE

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 1
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 15
       && total_diesel_needed == 11
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit26: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit26: FAILED");

      #10;

      if( pump_status == 6'b101000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 1
       && n_cars_in_diesel_queue == 3
       && total_gasoline_needed == 13
       && total_diesel_needed == 10
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit27: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit27: FAILED");

      #10;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 2
       && total_gasoline_needed == 12
       && total_diesel_needed == 10
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit28: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit28: FAILED");

      #120;

      if( pump_status == 6'b111000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 1
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 0
       && total_gasoline_needed == 0
       && total_diesel_needed == 0
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit29: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit29: FAILED");


      mode = 2'b10;                      // SETUP MODE
      n_gasoline_pumps = 6;
      n_diesel_pumps = 0;

      #10;

      if( pump_status == 6'b111111
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 0
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit30: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit30: FAILED");
      
      mode = 2'b01;                      // CAR ENTRANCE MODE
      fuel_type = 0;
      fuel_amount = 8;

      #10;
      
      if( pump_status == 6'b011111
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 8
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit31: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit31: FAILED");

      #50;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 33
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit32: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit32: FAILED");

      #50;

      if( pump_status == 6'b001000
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 3
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 45
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit33: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit33: FAILED");

      #150;

      if( pump_status == 6'b000000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 8
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 85
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit34: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit34: FAILED");

      #10;

      if( pump_status == 6'b100000
       && is_gasoline_queue_not_full == 0
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 8
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 79
       && total_diesel_needed == 255
       && invalid_gasoline_car == 1
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit35: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit35: FAILED");

      mode = 2'b00;                      // SIMULATION MODE
      #190;

      if( pump_status == 6'b111111
       && is_gasoline_queue_not_full == 1
       && is_diesel_queue_not_full == 0
       && n_cars_in_gasoline_queue == 0
       && n_cars_in_diesel_queue == 15
       && total_gasoline_needed == 0
       && total_diesel_needed == 255
       && invalid_gasoline_car == 0
       && invalid_diesel_car == 0
       && invalid_setup_params == 0) begin $display("timeUnit36: PASSED"); passCounter = passCounter + 1; end
                                     else  $display("timeUnit36: FAILED");



      
      
      $display("\n\n\n\t\t    ----------- END OF RESULTS -----------\n");
      $display("\n\t\tYou have passed     %d / 36\tof tests.\n\n", passCounter);

      $display("Result %d", passCounter);

      $finish;

    end

endmodule
