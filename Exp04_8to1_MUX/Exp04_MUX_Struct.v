module mux_8_1_struct(
    input [7:0] I,
    input [2:0] S,
    output Y
);
wire n0, n1, n2;
wire [7:0] w;
not (n0, S[0]);
not (n1, S[1]);
not (n2, S[2]);
and (w[0], I[0], n2, n1, n0);
and (w[1], I[1], n2, n1, S[0]);
and (w[2], I[2], n2, S[1], n0);
and (w[3], I[3], n2, S[1], S[0]);
and (w[4], I[4], S[2], n1, n0);
and (w[5], I[5], S[2], n1, S[0]);
and (w[6], I[6], S[2], S[1], n0);
and (w[7], I[7], S[2], S[1], S[0]);
or (Y, w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7]);
endmodule
