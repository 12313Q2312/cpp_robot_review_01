#ifndef BATTERY_H
#define BATTERY_H

class Battery {
	private:
		int Batterypower;
	public:
		Battery();
		//充电
		void charge(int val);
		//放电
		void discharge(int val);
		//获取电量
	int getPower() const;
		
};

#endif
