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

module Exp02_FA_2HA_tbw;
reg A, B, Cin;
wire Sum, Cout;

full_adder_2ha uut(.A(A), .B(B), .Cin(Cin), .Sum(Sum), .Cout(Cout));

initial begin
    A=0; B=0; Cin=0; #100;
    A=0; B=0; Cin=1; #100;
    A=0; B=1; Cin=0; #100;
    A=0; B=1; Cin=1; #100;
    A=1; B=0; Cin=0; #100;
    A=1; B=0; Cin=1; #100;
    A=1; B=1; Cin=0; #100;
    A=1; B=1; Cin=1; #100;
    // Add stimulus here
end
endmodule
