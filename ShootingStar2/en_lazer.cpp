#include"common.h"


int GetEmptyLazerIndex(){
	for(int i=0;i<EN_LAZER_MAX;i++){
		if(en_lazer[i].f==false)return i;
	}
	return -1;
}

void En_LazerSet(Position start,Position control,Position end,double v,double rad,int movePattern,int e_index,Bul_Color color,int div_num){
	int index = GetEmptyLazerIndex();
	if(index==-1)return;

	en_lazer[index].c=0;
	en_lazer[index].f=true;
	en_lazer[index].startPos=start;
	en_lazer[index].controlPos=control;
	en_lazer[index].endPos=end;
	en_lazer[index].v=v;
	en_lazer[index].trans_rad=rad;
	en_lazer[index].div_num=div_num;
	en_lazer[index].e_index=e_index;
	en_lazer[index].movePattern=movePattern;
	en_lazer[index].color=color;
	en_lazer[index].div_c=0;

	for(int i=0;i<EN_LAZER_DIV_MAX;i++){
		en_lazer[index].lazerDiv[i].f=false;
		en_lazer[index].lazerDiv[i].c=0;
	}
	en_lazer[index].lazerDiv[0].f=true;
	en_lazer[index].lazerDiv[0].center=start;
	en_lazer[index].lazerDiv[0].rad=rad;
	en_lazer[index].lazerDiv[0].start=true;
	en_lazer[index].lazerDiv[0].end=false;
}



//’Pƒ“™‘¬’¼i
void En_LazerMovePattern_00(int index,int div_index){
	en_lazer[index].lazerDiv[div_index].center.x+=en_lazer[index].v*cos(en_lazer[index].trans_rad);
	en_lazer[index].lazerDiv[div_index].center.y+=en_lazer[index].v*sin(en_lazer[index].trans_rad);
}

void(*En_LazerMovePattern[])(int,int)={
	En_LazerMovePattern_00
};

void LazerDivVissibleCheck(int index){
	for(int i=0;i<en_lazer[index].div_num;i++){
		if(en_lazer[index].lazerDiv[i].f==false) continue;
		if(en_lazer[index].lazerDiv[i].c<20) continue;

		if((en_lazer[index].lazerDiv[i].center.x < -gameData.eb_size[eb_lazer].width*cos(en_lazer[index].lazerDiv[i].rad)/2)
			||(en_lazer[index].lazerDiv[i].center.y < -gameData.eb_size[eb_lazer].height*sin(en_lazer[index].lazerDiv[i].rad)/2)
			||(en_lazer[index].lazerDiv[i].center.x > gameData.eb_size[eb_lazer].width*cos(en_lazer[index].lazerDiv[i].rad)/2 + FIELD_SIZE_WIDTH)
			||(en_lazer[index].lazerDiv[i].center.y > gameData.eb_size[eb_lazer].height*sin(en_lazer[index].lazerDiv[i].rad)/2 + FIELD_SIZE_HEIGHT)){
				en_lazer[index].lazerDiv[i].f=false;
		}
	}
}

bool IsLazerVissivle(int index){
	for(int i=0;i<en_lazer[index].div_num;i++){
		if(en_lazer[index].lazerDiv[i].f==true) return true;
	}
	return false;
}

void En_LazerCopy(int index,int div){
	while(en_lazer[index].lazerDiv[div].start==false){
		en_lazer[index].lazerDiv[div].center = en_lazer[index].lazerDiv[div-1].center;
		en_lazer[index].lazerDiv[div].rad = en_lazer[index].lazerDiv[div-1].rad;

		div--;
	}
}

void En_LazerMove(int index){
	for(int div=en_lazer[index].div_num-1;div>=0;div--){
		if(en_lazer[index].lazerDiv[div].f==false)continue;

		if(en_lazer[index].lazerDiv[div].end==true){
			En_LazerCopy(index,div);
		}
		if(en_lazer[index].lazerDiv[div].start==true){
			En_LazerMovePattern[en_lazer[index].movePattern](index,div);
		}
	}
}

void CheckLazerFlag(int index){
	if(en_lazer[index].lazerDiv[0].f==true){
		en_lazer[index].lazerDiv[0].start=true;
		if(en_lazer[index].lazerDiv[1].f==false){
			en_lazer[index].lazerDiv[0].end=true;
		}
		else{
			en_lazer[index].lazerDiv[0].end=false;
		}
	}
	if(en_lazer[index].lazerDiv[en_lazer[index].div_num-1].f==true){
		en_lazer[index].lazerDiv[en_lazer[index].div_num-1].end=true;
		if(en_lazer[index].lazerDiv[en_lazer[index].div_num-2].f==false){
			en_lazer[index].lazerDiv[en_lazer[index].div_num-1].start=true;
		}
		else{
			en_lazer[index].lazerDiv[en_lazer[index].div_num-1].start=false;
		}
	}
	for(int el_div_index=1;el_div_index<en_lazer[index].div_num-1;el_div_index++){
		if(en_lazer[index].lazerDiv[el_div_index].f==false) continue;

		if(en_lazer[index].lazerDiv[el_div_index-1].f==false){
			en_lazer[index].lazerDiv[el_div_index].start=true;
		}
		else{
			en_lazer[index].lazerDiv[el_div_index].start=false;
		}

		if(en_lazer[index].lazerDiv[el_div_index+1].f==false){
			en_lazer[index].lazerDiv[el_div_index].end=true;
		}
		else{
			en_lazer[index].lazerDiv[el_div_index].end=false;
		}
	}
}

void SetNewLazerDiv(int index){
	if(en_lazer[index].div_c==en_lazer[index].div_num)return;

	en_lazer[index].div_c++;
	
	en_lazer[index].lazerDiv[en_lazer[index].div_c].f=true;
	en_lazer[index].lazerDiv[en_lazer[index].div_c].c=0;
	en_lazer[index].lazerDiv[en_lazer[index].div_c].center = en_lazer[index].lazerDiv[en_lazer[index].div_c-1].center;
	en_lazer[index].lazerDiv[en_lazer[index].div_c].rad = en_lazer[index].lazerDiv[en_lazer[index].div_c-1].rad;
	en_lazer[index].lazerDiv[en_lazer[index].div_c].end=true;
	en_lazer[index].lazerDiv[en_lazer[index].div_c].start=false;
}

void En_LazerUpdate(){
	for(int i=0;i<EN_LAZER_MAX;i++){
		if(en_lazer[i].f==false)continue;

		SetNewLazerDiv(i);
		CheckLazerFlag(i);

		LazerDivVissibleCheck(i);
		en_lazer[i].f=IsLazerVissivle(i);
		En_LazerMove(i);

		en_lazer[i].c++;
		for(int j=0;j<EN_LAZER_DIV_MAX;j++){
			if(en_lazer[i].lazerDiv[j].f==false)continue;

			en_lazer[i].lazerDiv[j].c++;
		}
	}
}


void En_LazerDraw(){
	for(int i=0;i<EN_LAZER_MAX;i++){
		if(en_lazer[i].f==false)continue;

		for(int div=0;div<en_lazer[i].div_num;div++){
			if(en_lazer[i].lazerDiv[div].f==false)continue;

			SetDrawBlendMode(DX_BLENDMODE_ADD,50);
			DrawRotaGraph2(FIELD_OFFSET_X+Round(en_lazer[i].lazerDiv[div].center.x),FIELD_OFFSET_Y+Round(en_lazer[i].lazerDiv[div].center.y),
							gameData.eb_size[eb_lazer].width/2,gameData.eb_size[eb_lazer].height/2,1.5,en_lazer[i].lazerDiv[div].rad+M_PI/2,
							gameData.chip.e_bullet[eb_lazer][en_lazer[i].color],true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
		}
	}
}