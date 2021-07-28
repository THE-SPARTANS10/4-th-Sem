library IEEE;
use IEEE.std_logic_1164.all;
 
entity testbench is
-- empty
end testbench; 

architecture tb of testbench is

-- DUT component
component Full_ad is
port(
  a,b,c_in: in std_logic;
  s,c: out std_logic);
end component;

signal a_in, b_in, c_in, sum_out, carry_out: std_logic;

begin

  -- Connect DUT
  DUT: Full_ad port map(a_in, b_in, c_in, sum_out, carry_out);

  process
  begin
    a_in <= '0'; b_in <= '0'; c_in <= '0'; wait for 1 ns;
    
    a_in <= '0'; b_in <= '0'; c_in <= '1'; wait for 1 ns;
    
    a_in <= '0'; b_in <= '1'; c_in <= '0'; wait for 1 ns;
    
    a_in <= '0'; b_in <= '1'; c_in <= '1'; wait for 1 ns;
   
    a_in <= '1'; b_in <= '0'; c_in <= '0'; wait for 1 ns;
    
    a_in <= '1'; b_in <= '0'; c_in <= '1'; wait for 1 ns;
    
    a_in <= '1'; b_in <= '1'; c_in <= '0'; wait for 1 ns;
    
    a_in <= '1'; b_in <= '1'; c_in <= '1'; wait for 1 ns;
    wait;
  end process;
end tb;