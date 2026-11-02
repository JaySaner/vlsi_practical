`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date:
// Design Name:
// Module Name:
// Project Name:
// Target Device:
// Tool versions:
// Description: Verilog Test Fixture
//
// Dependencies:
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
////////////////////////////////////////////////////////////////////////////////

module pipo_tbw;
reg clk, rst, load;
reg [3:0] din;
wire [3:0] dout;
pipo uut(.clk(clk), .rst(rst), .load(load), .din(din), .dout(dout));
always #5 clk = ~clk;
initial begin
    clk=0; rst=1; load=0; din=4'b0000;
    #10 rst=0;
    din=4'b1011; load=1; #10;
    load=0; #100;
    // Add stimulus here
end
endmodule
