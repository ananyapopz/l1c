	
	uint8_t *dltti_array_ptr;
	int done=1;
void *thread1(){
while(1){
while(done == 1){pthread_yield();}
while(Pdu_Count < (int)Dl_ttiRequest.nPDUs)//size of total dltti pdu count
	{
		Dl_ttiRequest.DLPDU.PDUType = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
		Dl_ttiRequest.DLPDU.PDUSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
		//        xil_//printf("PT:%d,s:%x \r\n", Dl_ttiRequest.DLPDU.PDUType,Dl_ttiRequest.DLPDU.PDUSize);

		switch((int)Dl_ttiRequest.DLPDU.PDUType)
		{
		case PDCCH_PDU_TAG:
		{
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].BWPSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].BWPStart = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].SubcarrierSpacing = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].CyclicPrefix = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].StartSymbolIndex = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].DurationSymbols = (uint8_t)(*dltti_array_ptr++);
			//           xil_//printf("%x, %x, %x, %x, %x, %x\r\n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].BWPSize,Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].BWPStart,
			//           Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].SubcarrierSpacing,Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].CyclicPrefix,
			//				   Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].StartSymbolIndex,Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].DurationSymbols);
			//          xil_//printf("%d",MAX_FREQ_DOM_RESOURCE);

			for(var1 = 0;var1<MAX_FREQ_DOM_RESOURCE;var1++)
			{
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].FreqDomainResource[var1] = (uint8_t)(*dltti_array_ptr++);
				////////////////xil_//printf("fr[%d]= %d ",var1,Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].FreqDomainResource[var1]);
			}
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].CceRegMappingType = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].RegBundleSize = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].InterleaverSize = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].CoreSetType = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].ShiftIndex = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].precoderGranularity = (uint8_t)(*dltti_array_ptr++);
			//  ////xil_//printf("precoder granu= %d \n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].precoderGranularity);
			Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numDlDci = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8)); //23Bytes

			//           if(Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numDlDci!=1){
			//xil_//printf("E_cch,Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numDlDci \r\n");
			//           }
			for(var1 = 0;var1<(int)Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numDlDci;var1++)
			{
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].RNTI = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));// number dldcis yet to know the values
				////xil_//printf("%d",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[0].RNTI);

				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].ScramblingId = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].ScramblingRNTI = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].CceIndex = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].AggregationLevel = (uint8_t)(*dltti_array_ptr++);//31B
				//           Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.numPRGs = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				//           Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.prgSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				//           Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.digBFInterfaces = (uint8_t)(*dltti_array_ptr++);

				//          xil_//printf("PRGs: %d \r\n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.numPRGs);
				//  ////xil_//printf("digbf-interface = %d \n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.digBFInterfaces);
				//           if(Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.numPRGs!=1){
				//xil_//printf("E_cch@TxPrecoding_Beamforming.numPRGs \r\n");
				//           }
				//           for(var2=0;var2<(uint16_t)(Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.numPRGs);var2++)
				//           {
				//            Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				//   ////xil_//printf("[0]pmidx=%d \n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx);
				//           if(Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.digBFInterfaces!=4){
				//xil_//printf("E_cch@TxPrecoding_Beamforming.digBFInterfaces \r\n");
				//           }
				//            for(var3=0;var3<(uint8_t)(Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.digBFInterfaces);var3++)
				//            	{
				//            		Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3] = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				//   ////xil_//printf(" %d , var3 = %d\n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3] ,var3);
				//            	}
				//           }

				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].beta_PDCCH_1_0 = (uint8_t)(*dltti_array_ptr++);
				// ////xil_//printf("beta_pdcch=%d \n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].beta_PDCCH_1_0);
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].powerControlOffsetSS = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].PayloadSizeBits = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				//dci_payload_byte_len = ((float)Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].PayloadSizeBits/(float)8);
				//dci_payload_byte_len = ceil(dci_payload_byte_len);
				////xil_//printf("Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].PayloadSizeBits = %d \r\n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].PayloadSizeBits);
				////printf("dci_payload_byte_len = %f \r\n",dci_payload_byte_len);
				//35B
				//           xil_//printf("Po:%x\r\n",Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].powerControlOffsetSS);
				for(var2 = 0;var2<(int)((Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].PayloadSizeBits+7)/8) ;var2++)
				{
					Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].Payload[var2] = (uint8_t)(*dltti_array_ptr++);
					//       xil_//printf("payload[%d] = %d \n ",var2,Dl_ttiRequest.PDCCH_PDU[Pdcch_Count].numOfDlDcis[var1].Payload[var2] );

				}
			}
			Pdcch_Count = Pdcch_Count+1;
			//          //xil_//printf("------------------------------------------Pdcch_Count--------------------------------------- %d\r\n",Pdcch_Count);
			break;
		}


		case PDSCH_PDU_TAG:
		{
			//            ////xil_//printf("PDsCH_PDU_TAG\r\n");
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].pduBitmap = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//////xil_//printf("i=%d , Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].pduBitmap = %d \r\n", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].pduBitmap);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].RNTI = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].RNTI = %d \r\n", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].RNTI);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].pduIndex =  (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].BWPSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].BWPStart = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].SubcarrierSpacing = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CyclicPrefix = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].NrOfCodewords = (uint8_t)(*dltti_array_ptr++);
			//////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].NrOfCodewords = %d \r\n", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].NrOfCodewords);
			for(var1=0;var1<(int)(Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].NrOfCodewords);var1++)
			{
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].targetCodeRate = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].qamModOrder =  (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].mcsIndex = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].mcsTable = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].rvIndex = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].TBSize = (uint32_t)(((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8)) | ((*dltti_array_ptr++)<<16) | ((*dltti_array_ptr++)<<24));
				// ////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].TBSize = %d \r\n",Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].CodewordInfo[var1].TBSize);
			}

			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dataScramblingId = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			// ////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dataScramblingId = %d \r\n", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dataScramblingId);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].nrOfLayers = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].transmissionScheme = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].refPoint = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dlDmrsSymbPos = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dmrsConfigType = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dlDmrsScramblingId = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].SCID = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].numDmrsCdmGrpsNoData = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dmrsPorts = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].resourceAlloc = (uint8_t)(*dltti_array_ptr++);
			// ////xil_//printf(" Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].resourceAlloc = %d \r\n", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].resourceAlloc);
			for(var2 = 0;var2<(int)(MAX_RB_BITMAP);var2++)
			{
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbBitmap[var2] = (uint8_t)(*dltti_array_ptr++);
				//////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbBitmap[var2] = %d \r\n ",Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbBitmap[var2] );
			}
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbStart = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			// ////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbSize = %d \r\n ",Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbSize);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].VRBtoPRBMapping = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].StartSymbolIndex = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].NrOfSymbols = (uint8_t)(*dltti_array_ptr++);
			if(((int)Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].pduBitmap & 0b0001))
			{
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].PTRSPortIndex = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].PTRSTimeDensity = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].PTRSFreqDensity = (uint8_t)(*dltti_array_ptr++);
				//////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].PTRSFreqDensity = %d \r\n", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].PTRSFreqDensity);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].PTRSReOffset = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].nEpreRatioOfPDSCHToPTRS = (uint8_t)(*dltti_array_ptr++);
			}
			// 	       Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.numPRGs = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//          // ////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.numPRGs = %d \r\n ", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.numPRGs);
			// 	       Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.prgSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			// 	       Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.digBFInterfaces = (uint8_t)(*dltti_array_ptr++);
			// ////xil_//printf(" Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.digBFInterfaces = %d \r\n ", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.digBFInterfaces);
			// 	       for(var2=0;var2<(int)(Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.numPRGs);var2++)
			//           {
			//            Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//            for(var3=0;var3<(int)(Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.digBFInterfaces);var3++)
			//           {
			//        	   Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3]  = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           }
			//          // ////xil_//printf(" Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.NumOfPRGs[%d].PMidx = %d \r\n",var2,Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx);
			//           }

			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].powerControlOffset = (uint8_t)(*dltti_array_ptr++);
			//           xil_//printf("p: %d \r\n",Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].powerControlOffset);
			Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].powerControlOffsetSS = (uint8_t)(*dltti_array_ptr++);
			if(((int)Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].pduBitmap & 0b0010))
			{
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].IsLastCbPresent = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].isInlineTbCrc = (uint8_t)(*dltti_array_ptr++);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dlTbCrc = (uint32_t)(((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8)) | ((*dltti_array_ptr++)<<16) | ((*dltti_array_ptr++)<<24));
				//////xil_//printf("Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dlTbCrc = %d \r\n ", Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].dlTbCrc);
			}
			// Currently we support only the contiguous allocation, so we convert the bitmap to contiguous allocation if Resource Allocation = 0 and process the Allocation as type 1
			if( Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].resourceAlloc == 0 ){
				int rbStart, rbSize ;
				get_contiguous_RB_alloc_from_bitmap(Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbBitmap,&rbStart,&rbSize);
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].resourceAlloc = 1;
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbStart = rbStart;
				Dl_ttiRequest.PDSCH_PDU[Pdsch_Count].rbSize = rbSize;
			}

			Pdsch_Count = Pdsch_Count+1;
			//xil_//printf("Pd= %d",Pdsch_Count);
			break;
		}


		case CSIRS_PDU_TAG:
			//        	   //////////xil_//printf("csirs_PDU_TAG");
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			// //printf("BWP size is %d",Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPSize);
			if(Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPSize>273){
				// Chnage from 276 to 273
				Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPSize = 273;
			}	
			////////////////xil_//printf("Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPSize = %d", Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPSize);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPStart = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			////////////////xil_//printf("Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPStart = %x ", Dl_ttiRequest.CSIRS_PDU[Csirs_Count].BWPStart);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].SubcarrierSpacing = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].CyclicPrefix = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].StartRB = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].NrOfRBs = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			if(Dl_ttiRequest.CSIRS_PDU[Csirs_Count].NrOfRBs>273)
				Dl_ttiRequest.CSIRS_PDU[Csirs_Count].NrOfRBs = 273;
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].CSIType = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].Row = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].FreqDomain = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].SymbL0 = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].SymbL1 = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].CDMType = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].FreqDensity = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].ScrambId = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].powerControlOffset = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.CSIRS_PDU[Csirs_Count].powerControlOffsetSS = (uint8_t)(*dltti_array_ptr++);
			////////////////xil_//printf("Dl_ttiRequest.CSIRS_PDU[Csirs_Count].powerControlOffset = %x ", Dl_ttiRequest.CSIRS_PDU[Csirs_Count].powerControlOffset);
			//          Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.numPRGs = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//          Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.prgSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//          Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.digBFInterfaces = (uint8_t)(*dltti_array_ptr++);
			//           ////////////////xil_//printf("Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.digBFInterfaces = %x ", Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.digBFInterfaces);
			//           for(var2=0;var2<(int)(Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.numPRGs);var2++)
			//           {
			//         Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           for(var3=0;var3<(int)(Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.prgSize);var3++)
			//           {
			//          Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3]  = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           }
			//       ////////////////xil_//printf("Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.NumOfPRGs[%d].PMidx=%d",var2,Dl_ttiRequest.CSIRS_PDU[Csirs_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx);
			//           }
			Csirs_Count = Csirs_Count+1;
			//          //xil_//printf("------------------------------------------csirs_Count--------------------------------------- %d",Csirs_Count);
			break;

		case SSB_PDU_TAG:
			//            	 //////////xil_//printf("ssb_PDU_TAG");
			Dl_ttiRequest.SSB_PDU[Ssb_Count].physCellId = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           xil_//printf("celid =%d \n",Dl_ttiRequest.SSB_PDU[Ssb_Count].physCellId);
			Dl_ttiRequest.SSB_PDU[Ssb_Count].betaPss = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.SSB_PDU[Ssb_Count].ssbBlockIndex = (uint8_t)(*dltti_array_ptr++);
			////////////////xil_//printf("Dl_ttiRequest.SSB_PDU[Ssb_Count].ssbBlockIndex = %x ", Dl_ttiRequest.SSB_PDU[Ssb_Count].ssbBlockIndex);
			Dl_ttiRequest.SSB_PDU[Ssb_Count].ssbSubcarrierOffset = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.SSB_PDU[Ssb_Count].SsbOffsetPointA = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayloadFlag = (uint8_t)(*dltti_array_ptr++);
			Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayload.MACgenMIBPDU.bchPayload = (uint32_t)(((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8)) | ((*dltti_array_ptr++)<<16) | ((*dltti_array_ptr++)<<24));
			//           xil_//printf("%d",Dl_ttiRequest.SSB_PDU[Ssb_Count].physCellId);//%d,%d,%d,%d,%d,%d \r\n",Dl_ttiRequest.SSB_PDU[Ssb_Count].physCellId,Dl_ttiRequest.SSB_PDU[Ssb_Count].betaPss,Dl_ttiRequest.SSB_PDU[Ssb_Count].ssbBlockIndex,
			//           Dl_ttiRequest.SSB_PDU[Ssb_Count].ssbSubcarrierOffset,Dl_ttiRequest.SSB_PDU[Ssb_Count].SsbOffsetPointA,
			//		   Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayloadFlag,Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayload.MACgenMIBPDU.bchPayload);
			////////////////xil_//printf("Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayload.MACgenMIBPDU.bchPayload  = %x ", Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayload.MACgenMIBPDU.bchPayload );
			//           Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.numPRGs = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.prgSize = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.digBFInterfaces = (uint8_t)(*dltti_array_ptr++);
			//           ////////////////xil_//printf("Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.numPRGs = %x", Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.numPRGs);
			//           ////////////////xil_//printf("Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.digBFInterfaces = %x ", Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.digBFInterfaces);
			//           if(Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.numPRGs!=1){
			//        	   //xil_//printf("E_ssb@TxPrecoding_Beamforming.numPRGs \r\n");
			//           }
			//           for(var2=0;var2<(int)(Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.numPRGs);var2++)
			//           {
			//           Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].PMidx= (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           for(var3=0;var3<(int)(Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.digBFInterfaces);var3++)
			//           {
			//           Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3] = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
			//           }
			//            ////////////////xil_//printf("Dl_ttiRequest.SSB_PDU[Ssb_Count].numOfDlDcis[0].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3] = %x ",var2,var3, Dl_ttiRequest.SSB_PDU[Ssb_Count].TxPrecoding_Beamforming.NumOfPRGs[var2].beamIdx[var3]);
			//           }
			ConfigRequest.SSBTable.MIB.Value = Dl_ttiRequest.SSB_PDU[Ssb_Count].bchPayload.MACgenMIBPDU.bchPayload;
			Ssb_Count = Ssb_Count +1;
			//xil_//printf("Ss %d \r\n",Ssb_Count);
			break;

		default:
			break;

		}

		Pdu_Count=Pdu_Count+1;
		////xil_//printf("Pdu Count = %d\r\n",Pdu_Count);
	}
	done = 1;
}
}

void get_dl_tti_request_data_from_hex_string(char* fapiHexDlttiReq_i)
{

	uint32_t Pdu_Count=0;
	uint32_t Pdcch_Count = 0;
	uint32_t Pdsch_Count = 0;
	uint32_t Csirs_Count = 0;
	uint32_t Ssb_Count = 0;
	uint32_t nUe_Count = 0;
	uint32_t nUe_Pdu_Count = 0,Group_Count =0;
	uint32_t var1=0,var2=0,var3=0,var4=0;
	uint32_t pdu_size = 0;
        uint32_t *dltti_array_ptr_32b;

	/* For sw code, read fapi message in hex format and convert it to binary */
	uint8_t fapiBytesDlttiReq[MAX_FAPI_BYTES];
	int numFapiBytes = convertHex2DecBytes(fapiHexDlttiReq_i, fapiBytesDlttiReq);
	// validate fapi message
	if(numFapiBytes > MAX_FAPI_BYTES)
	{
		//printf("Error in get_dl_tti_request_data(): Number of Fapi message bytes exceeds allocated limit\n");
		return;
	}

	char fapiHeader[9];
	memcpy(fapiHeader,fapiHexDlttiReq_i,8);
	fapiHeader[8]='\0';
	if(0!=strcmp("01008000",fapiHeader))//0100 will be the message header, 8000 is message id
	{
		//printf("Error in get_dl_tti_request_data(): Invalid Fapi message bytes\n");
		return;
	}

	float dci_payload_byte_len;
	dltti_array_ptr_32b = (uint32_t *)(fapiBytesDlttiReq + 4);
	Dl_ttiRequest.MsgLength = (dltti_array_ptr_32b[0]);
	Dl_ttiRequest.SFN=(uint16_t) *((uint16_t *)(dltti_array_ptr_32b+1));
	pdu_size = (Dl_ttiRequest.MsgLength);
	////////////////xil_//printf("pdu_size = %x ", pdu_size);
	dltti_array_ptr = fapiBytesDlttiReq + 10;
	Dl_ttiRequest.Slot = (uint16_t)((*dltti_array_ptr++) | ((*dltti_array_ptr++)<<8));
	Dl_ttiRequest.nPDUs = (uint8_t)(*dltti_array_ptr++);
	Dl_ttiRequest.nGroup = (uint8_t)(*dltti_array_ptr++);
	//     xil_//printf("s:%x, p:%x\r\n",Dl_ttiRequest.Slot,Dl_ttiRequest.nPDUs);
	////xil_//printf("Dl_ttiRequest.MsgLength = %d\r\n", Dl_ttiRequest.MsgLength);
	//     //xil_//printf("Dl_ttiRequest.SFN = %d \r\n", Dl_ttiRequest.SFN);
	//xil_//printf("%d \r\n", Dl_ttiRequest.Slot);
	//      //xil_//printf("Dl_ttiRequest.nPDUs = %d \r\n", Dl_ttiRequest.nPDUs);
	//      //xil_//printf("Dl_ttiRequest.nGroup = %d \r\n ", Dl_ttiRequest.nGroup);

done = 0;
while(done == 0){
pthread_yield();
}
done = 1;
	
	//condition checks
	if(Dl_ttiRequest.nGroup!=8)
	{
		//xil_//printf("Error at DL_tti:Dl_ttiRequest.nGroup \r\n");
	}
	while(Group_Count<(int)(Dl_ttiRequest.nGroup))
	{
		Dl_ttiRequest.UeList[nUe_Count].nUe = (uint8_t)(*dltti_array_ptr++);
		if(Dl_ttiRequest.UeList[nUe_Count].nUe>4){  //nUe range from 1 to 4
			//xil_//printf("E@Dl_ttiRequest.UeList[nUe_Count].nUe \r\n");
		}
		for(var1=0;var1<(int)(Dl_ttiRequesint8_t *dltti_array_ptr;t.UeList[nUe_Count].nUe);var1++)
		{
			Dl_ttiRequest.UeList[nUe_Count].PduIdx[var1] = (uint8_t)(*dltti_array_ptr++);
			////////////////xil_//printf("Dl_ttiRequest.UeList[nUe_Count].PduIdx[%d]  = %x",var1,Dl_ttiRequest.UeList[nUe_Count].PduIdx[var1]);
		}
		nUe_Count = nUe_Count + 1;
		////////////////xil_//printf("------------------------------------------nUe_Count--------------------------------------- %d\n",nUe_Count);
		Group_Count = Group_Count+1;
	}
	//l1_downlink_chain
	Dl_tti_intermediate.nPDSCH = Pdsch_Count;
	Dl_tti_intermediate.nPDCCH = Pdcch_Count;
	Dl_tti_intermediate.nCSIRS = Csirs_Count;
	Dl_tti_intermediate.nSSB = 0;

	//////////////////////////////////////////////////////////////////////////////////////////////
	// SSB symbol index calculation in a half-frame: Case C (TS 38.213): {2,8}+14*n, n=0,1,2,3.
	//  So, possible SSB symbol positions are: 2,8,16,22,30,36,44,50
	//          -- Minimum = 2  in slot0  ( repeat for slot10 if SsbPeriod=0 for 5ms period)
	//          -- Maximum = 50 in slot3  ( repeat for slot13 if SsbPeriod=0 for 5ms period)
	// So SSB will be transmitted only during the first 4 slots of every "half-frame".
	// SSB Mask[0] bitmap determines which of these symbols are actually present
	//   -- bitmap order is MSB first. Only consider first 8 MSB bits, i.e.
	//             -- bit31 = 1 => SSB present at symbol 2  (slot0)
	//             -- bit30 = 1 => SSB present at symbol 8  (slot0)
	//             -- bit29 = 1 => SSB present at symbol 16 (slot1, symbol2)
	//             -- bit28 = 1 => SSB present at symbol 22 (slot1, symbol8)
	//             -- bit27 = 1 => SSB present at symbol 30 (slot2, symbol2)
	//             -- bit26 = 1 => SSB present at symbol 36 (slot2, symbol8)
	//             -- bit25 = 1 => SSB present at symbol 44 (slot3, symbol2)
	//             -- bit24 = 1 => SSB present at symbol 50 (slot3, symbol8)
	//////////////////////////////////////////////////////////////////////////////////////////////
	if (Dl_ttiRequest.Slot%10 <=3 ){ // Only needs to check first 4 slots of every "half-frame" for possible SSB transmission
		if (ConfigRequest.SSBTable.SsbPeriod.Value == 0){ // 5ms period
			if (ConfigRequest.SSBTable.SsbMask[0].Value & (uint32_t)((uint32_t)1<<(32-2*(Dl_ttiRequest.Slot%10)-1)))
				Dl_tti_intermediate.nSSB += 1; // symbol2 present
			if (ConfigRequest.SSBTable.SsbMask[0].Value & (uint32_t)((uint32_t)1<<(32-2*(Dl_ttiRequest.Slot%10)-2)))
				Dl_tti_intermediate.nSSB += 2; // symbol8 present
		}
		else{
			if (Dl_ttiRequest.SFN%ConfigRequest.SSBTable.SsbPeriod.Value == 0){
				if (ConfigRequest.SSBTable.SsbMask[0].Value & (uint32_t)((uint32_t)1<<(32-2*Dl_ttiRequest.Slot-1)))
					Dl_tti_intermediate.nSSB += 1; // symbol2 present
				if (ConfigRequest.SSBTable.SsbMask[0].Value & (uint32_t)((uint32_t)1<<(32-2*Dl_ttiRequest.Slot-2)))
					Dl_tti_intermediate.nSSB += 2; // symbol8 present
			}
		}
	}

	// validation: check if SSB is received as per configuration
	if ((Ssb_Count>0) && (Dl_tti_intermediate.nSSB==0)){
		///////////////////////////////////////////
		// TODO: When ConfigRequest.SSBTable.SsbPeriod.Value > 1 ( i.e. period >= 20 ms), there could be an error scenario such that
		// SSB pdu is received from Sooktha in the current SFN, but  Dl_ttiRequest.SFN%ConfigRequest.SSBTable.SsbPeriod.Value != 0
		// This case happens when SSB transmitted with a frame number offset, say "ssbFrameOffset" such that
		// (Dl_ttiRequest.SFN+ssbFrameOffset)%ConfigRequest.SSBTable.SsbPeriod.Value = 0. Not sure if this will happen. But if it happens
		//  we may have to find value of "ssbFrameOffset" using the SFN for which SSB pdu is received from Sooktha and then replace the condition
		//     if  ((Dl_ttiRequest.SFN)%ConfigRequest.SSBTable.SsbPeriod.Value == 0)
		//   to
		//     if  ((Dl_ttiRequest.SFN+ssbFrameOffset)%ConfigRequest.SSBTable.SsbPeriod.Value == 0)
		// For that we can use ssbFrameOffset as a static variable and find its value only when Ssb_Count > 0.
		////////////////////////////////////////////
		//printf("\nError: SSB pdu is received in wrong slot=%d or wrong SFN=%d where SsbPeriod=%d, SsbMask=0x%x\n",Dl_ttiRequest.Slot,Dl_ttiRequest.SFN,ConfigRequest.SSBTable.SsbPeriod.Value,ConfigRequest.SSBTable.SsbMask[0].Value);
	}
}
