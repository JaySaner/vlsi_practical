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

module T_FF_tbw;
reg clk, rst, T;
wire Q;

T_FF uut(.clk(clk), .rst(rst), .T(T), .Q(Q));
always #5 clk = ~clk;

initial begin
    clk=0; rst=1; T=0;
    #10 rst=0;
    T=0; #100;
    T=1; #100;
    T=0; #100;
    T=1; #100;
    // Add stimulus here
end
endmodule
