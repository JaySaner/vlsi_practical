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

module Exp03_FS_tbw;
reg A, B, Bin;
wire D, Bout;

full_subtractor uut(.A(A), .B(B), .Bin(Bin), .D(D), .Bout(Bout));

initial begin
    A=0; B=0; Bin=0; #100;
    A=0; B=0; Bin=1; #100;
    A=0; B=1; Bin=0; #100;
    A=0; B=1; Bin=1; #100;
    A=1; B=0; Bin=0; #100;
    A=1; B=0; Bin=1; #100;
    A=1; B=1; Bin=0; #100;
    A=1; B=1; Bin=1; #100;
    // Add stimulus here
end
endmodule
