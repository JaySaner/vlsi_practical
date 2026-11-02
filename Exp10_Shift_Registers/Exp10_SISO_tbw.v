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

module siso_tbw;
reg clk, rst, din;
wire q;
siso uut(.clk(clk), .rst(rst), .din(din), .q(q));
always #5 clk = ~clk;
initial begin
    clk=0; rst=1; din=0;
    #10 rst=0;
    din=1; #10;
    din=0; #10;
    din=1; #10;
    din=1; #10;
    din=0; #50;
    // Add stimulus here
end
endmodule
