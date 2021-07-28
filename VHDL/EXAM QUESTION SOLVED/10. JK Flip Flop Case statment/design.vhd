library IEEE; 
use IEEE.std_logic_1164.all;  

entity JK is 
   port(
      J,K,CLK,RST : in STD_LOGIC; 
      Q,QB : out STD_LOGIC); 
end JK;
  
architecture bhv of JK is
signal s:std_logic:='0';
signal jk: std_logic_vector(1 downto 0);
begin 
   process (J,K,CLK,RST) is  
   begin 
   jk <= j&k;
      if (RST = '1') then 
         s<='0';
      elsif (rising_edge (clk)) then 
        case(jk)is
    		when "00"=>s<= s;
    		when "10"=>s<='1';
    		when "01"=>s<='0';
    		when others=> s<=not s;
    	end case;
      end if;
   end process;
   Q <=s; QB<= not s;
end bhv;