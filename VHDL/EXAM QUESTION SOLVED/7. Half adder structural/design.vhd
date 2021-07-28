library IEEE;
use IEEE.std_logic_1164.all;
entity andgate is
    port(
        A, B: in std_logic;
        Y: out std_logic;
    );
end andgate;

library IEEE;
use IEEE.std_logic_1164.all;
entity xorgate is
    port(
        A, B: in std_logic;
        Y: out std_logic;
    );
end xorgate;

library IEEE;
use IEEE.std_logic_1164.all;
entity halfadder is
    port(
        A, B: in std_logic;
        S, C: out std_logic;
    );
end halfadder;


architecture arch_andgate of andgate is
begin
    process(A, B)
    begin
        Y <= A and B;
    end process;
end arch_andgate;

architecture arch_xorgate of xorgate is
begin
    process(A, B)
    begin
        Y <= A xor B;
    end process;
end arch_xorgate;

architecture arch_halfadder of halfadder is
component andgate is
    port(
        A, B: in std_logic;
        Y: out std_logic;
    );
end andgate;

component xorgate is
    port(
        A, B: in std_logic;
        Y: out std_logic;
    );
end xorgate;

begin
    M1: xorgate port map(A, B, S);
    M2: andgate port map(A, B, C);
end arch_halfadder;