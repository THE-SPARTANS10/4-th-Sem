library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

--DUT Component
component halfadder is
port(
        A, B: in std_logic;
        S, C: out std_logic;
    );
end component;
 
signal a_in, b_in, s_out, c_out: std_logic;
 
begin
 
 --Connect DUT
 DUT: halfadder port map(a_in, b_in, s_out, c_out);
 
 process
 begin
  a_in <= '0';
  b_in <= '0';
  wait for 1 ns;
  
  a_in <= '0';
  b_in <= '1';
  wait for 1 ns;
  
  a_in <= '1';
  b_in <= '0';
  wait for 1 ns;
  
  a_in <= '1';
  b_in <= '1';
  wait for 1 ns;
  
  --assert false report "Test done." severity note;
  wait;
 end process;
end tb;