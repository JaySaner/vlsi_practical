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

module sipo_tbw;
reg clk, din;
wire [3:0] q;
sipo uut(.clk(clk), .din(din), .q(q));
always #5 clk = ~clk;
initial begin
    clk=0; din=0;
    #10 din=1; #10;
    din=0; #10;
    din=1; #10;
    din=1; #10;
    // Add stimulus here
end
endmodule
