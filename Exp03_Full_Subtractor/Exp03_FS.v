module full_subtractor(
    input A, input B, input Bin,
    output reg D, output reg Bout
);
always @(*) begin
    D = A ^ B ^ Bin;
    Bout = (~A & B) | (~(A ^ B) & Bin);
end
endmodule
