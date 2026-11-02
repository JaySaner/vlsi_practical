module T_FF(
    input clk,
    input rst,
    input T,
    output reg Q
);
always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 0;
    else
        Q <= Q ^ T;
end
endmodule
