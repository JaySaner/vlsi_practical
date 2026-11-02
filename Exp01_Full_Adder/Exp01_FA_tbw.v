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

module Exp01_FA_tbw;
reg A, B, Cin;
wire Sum_beh, Cout_beh, Sum_struct, Cout_struct;

full_adder_beh U1(.A(A), .B(B), .Cin(Cin), .Sum(Sum_beh), .Cout(Cout_beh));
full_adder_struct U2(.A(A), .B(B), .Cin(Cin), .Sum(Sum_struct), .Cout(Cout_struct));

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
