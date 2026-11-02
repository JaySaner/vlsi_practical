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

module UP_DOWN_tbw;
reg clk, rst, cnt;
wire [3:0] Q;

UP_DOWN uut(.clk(clk), .rst(rst), .cnt(cnt), .Q(Q));
always #5 clk = ~clk;

initial begin
    clk=0; rst=1; cnt=1;
    #10 rst=0;
    cnt=1; #100;
    cnt=1; #100;
    cnt=1; #100;
    cnt=0; #100;
    cnt=0; #100;
    cnt=0; #100;
    // Add stimulus here
end
endmodule
