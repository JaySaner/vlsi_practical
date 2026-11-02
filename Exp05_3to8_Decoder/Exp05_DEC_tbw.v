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

module Exp05_DEC_tbw;
reg A, B, C;
wire [7:0] Y_beh, Y_struct;

decoder_38_beh U1(.A(A), .B(B), .C(C), .Y(Y_beh));
decoder_38_struct U2(.A(A), .B(B), .C(C), .Y(Y_struct));

initial begin
    A=0; B=0; C=0; #100;
    A=0; B=0; C=1; #100;
    A=0; B=1; C=0; #100;
    A=0; B=1; C=1; #100;
    A=1; B=0; C=0; #100;
    A=1; B=0; C=1; #100;
    A=1; B=1; C=0; #100;
    A=1; B=1; C=1; #100;
    // Add stimulus here
end
endmodule
