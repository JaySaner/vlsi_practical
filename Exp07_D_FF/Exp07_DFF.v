module D_FF(
    input clk,
    input rst,
    input D,
    output reg Q
);
always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 0;
    else
        Q <= D;
end
endmodule
