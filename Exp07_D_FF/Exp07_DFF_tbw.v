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

module D_FF_tbw;
reg clk, rst, D;
wire Q;

D_FF uut(.clk(clk), .rst(rst), .D(D), .Q(Q));
always #5 clk = ~clk;

initial begin
    clk=0; rst=1; D=0;
    #10 rst=0;
    D=0; #100;
    D=1; #100;
    D=0; #100;
    D=1; #100;
    // Add stimulus here
end
endmodule
